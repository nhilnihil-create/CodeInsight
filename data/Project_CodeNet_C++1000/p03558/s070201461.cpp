#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = /*1'000'000'007LL;*/ 998'244'353LL;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int K;
bool canVis[100000][46];

void solve(int n, int k){
    canVis[n][k] = true;
    rep(i, 10){
        if(i > k) break;
        if(!canVis[(10*n+i)%K][k-i]){
            solve((10*n+i)%K, k-i);
        }
    }
}

signed main(){
    cin >> K;
    for(int i=1; i<=9*5; i++){
        memset(canVis, false, sizeof(canVis));
        solve(0, i);
        if(canVis[0][0]){
            cout << i << endl;
            return 0;
        }
    }
}