#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
int A[200000], B[200000];

signed main(){
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int ans = 0;
    rep(k, 29){
        int cnt = 0;
        vector<pair<int, int>> P0, P1;
        rep(i, N){
            if((B[i]>>k)&1) P1.pb({ B[i]%(1<<k),B[i] });
            else P0.pb({ B[i]%(1<<k),B[i] });
        }
        sort(all(P0)); sort(all(P1));
        rep(i, N){
            if((A[i]>>k)&1){
                cnt += lower_bound(all(P0), mp((1<<k)-A[i]%(1<<k),0)) - P0.begin();
                cnt += P1.end() - lower_bound(all(P1), mp((1<<k)-A[i]%(1<<k),0));
            }
            else{
                cnt += P0.end() - lower_bound(all(P0), mp((1<<k)-A[i]%(1<<k),0));
                cnt += lower_bound(all(P1), mp((1<<k)-A[i]%(1<<k),0)) - P1.begin();
            }
            cnt &= 1;
        }
        ans += cnt<<k;
    }
    cout << ans << endl;
}