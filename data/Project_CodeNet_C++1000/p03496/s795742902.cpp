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
int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    vector<pair<int,int>> ans;

    int positive = 0;
    int pm = 0;
    int pmidx = 0;
    int negative = 0;
    int nm = 0;
    int nmidx = 0;
    int zero = 0;
    rep(i, n){
        if(a[i] > 0){
            positive++;
            if(pm < a[i]){
                pm = a[i];
                pmidx = i;
            }
        } else if(a[i] < 0){
            negative++;
            if(nm > a[i]){
                nm = a[i];
                nmidx = i;
            }
        } else {
            zero++;
        }
    }

    if(positive == n - zero){
        for(int i = 1; i < n; i++){
            ans.push_back({i - 1, i});
        }
    } else if(negative == n - zero){
        for(int i = n - 2; i >= 0; i--){
            ans.push_back({i + 1, i});
        }
    } else {
        int po = 0;
        int ne = 0;
        int necp = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < 0){
                necp += (abs(a[i]) - 1) / pm + 1;
            }
        }
        int necn = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                necn += (abs(a[i]) - 1) / -nm + 1;
            }
        }
        if(necp <= necn){
            for(int i = 0; i < n; i++){
                if(a[i] < 0){
                    int nec = (abs(a[i]) - 1) / pm + 1;
                    while(nec > 0){
                        ans.push_back({pmidx, i});
                        nec--;
                    }
                }
            }
            for(int i = 1; i < n; i++){
                ans.push_back({i - 1, i});
            }
        } else {
            for(int i = 0; i < n; i++){
                if(a[i] >= 0){
                    int nec = (abs(a[i]) - 1) / -nm + 1;
                    while(nec > 0){
                        ans.push_back({nmidx, i});
                        nec--;
                    }
                }
            }
            for(int i = n - 2; i >= 0; i--){
                ans.push_back({i + 1, i});
            }       
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

}