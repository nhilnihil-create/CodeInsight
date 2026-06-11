#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long N; cin>>N;
    vector<long> a(5, 0);

    char c[5] = {'M','A','R','C','H'};
    ll count = 0;
    rep(i, N){
        string S; cin>>S;
        rep(j, 5){
            if(S[0] == c[j]){
                a[j]++;
                count++;
                break;
            }
        }
    }

    ll ans = 0;
    rep(i, 5){
       FOR(j, i+1, 5){
           FOR(k, j+1, 5){
               ans += a[i]*a[j]*a[k];
           }
       }
    }

    cout << ans << endl;
}
