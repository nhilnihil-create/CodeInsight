/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

ll cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
map<int,int> mp;
int ans = 0;
void dfs(int now, vector<int> pos){
    if(now == 13){
        int tmp = 1e9;
        rep(i, pos.size()){
            rep(j, pos.size()){
                if(i == j) continue;
                tmp = min({tmp, pos[i] + (24 - pos[j]), abs(pos[i] - pos[j])});
            }
        }
        ans = max(ans, tmp);
        return;
    }

    if(mp[now] == 2){
        pos.push_back(now);
        pos.push_back(24 - now);
        dfs(now + 1, pos);
    } else if(mp[now] == 1){
        vector<int> next = pos;
        next.push_back(now);
        dfs(now + 1, next);
        if(now != 0 || now != 12){
            next = pos;
            next.push_back(24 - now);
            dfs(now + 1, next);
        }
    } else {
        dfs(now + 1, pos);
    }
}
int main(void){
    int n;
    cin >> n;

    mp[0] = 1;
   
    rep(i, n){
        int d;
        cin >> d;
        mp[d]++;
    }

    for(auto &i : mp){
        if(i.second > 2){
            cout << 0 << endl;
            return 0;
        }
    }

    if(mp[0] >= 2 || mp[12] >= 2){
        cout << 0 << endl;
        return 0;
    }

    vector<int> pos;
    dfs(0, pos);
    cout << ans << endl;
}