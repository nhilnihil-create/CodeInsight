/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
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
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
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
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------

int main(void){
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c + 1, vector<int>(c + 1));

    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= c; j++){
            cin >> d[i][j];
        }
    }

    vector<vector<int>> grid(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> cs(3, vector<int>(c + 1, 0));


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cs[(i + j) % 3][grid[i][j]]++;
        }
    }
    ll ans = INF;
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= c; j++){
            for(int k = 1; k <= c; k++){
                if(i == k || j == k || i == j) continue;
                ll tmpans = 0;
                for(int l = 1; l < cs[0].size(); l++){
                    tmpans += d[l][i] * cs[0][l];
                }
                for(int l = 1; l < cs[1].size(); l++){
                    tmpans += d[l][j] * cs[1][l];
                }
                for(int l = 1; l < cs[2].size(); l++){
                    tmpans += d[l][k] * cs[2][l];
                }
                
                ans = min(ans, tmpans);

            }
        }
    }
    cout << ans << endl;

    
}