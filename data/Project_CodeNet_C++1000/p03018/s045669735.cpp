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

string S;
ll cnt[200001];

signed main(){
    cin >> S;
    ll ans = 0;
    for(int i=S.size()-1; i>=0; i--){
        if(S[i] == 'A') ans += (cnt[i] = cnt[i+1]);
        if(S[i] == 'B'){
            cnt[i] = 0;
            if(i+1 < S.size() && S[i+1] == 'C')
                cnt[i] = cnt[i+2] + 1;
        }
        if(S[i] == 'C') cnt[i] = 0;
    }
    cout << ans << endl;
}