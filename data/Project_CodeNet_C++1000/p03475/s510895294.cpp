#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;


int main(){
    ll N;
    cin >> N;
    
    vector<ll> ans(N,0);
    vector<ll> C(N - 1,0);
    vector<ll> S(N - 1,0);
    vector<ll> F(N - 1,0);
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];
    rep(i,N - 1){
        ll now = 0;
        for(int j = i; j < N - 1; j++){
            if(now < S[j] || (now - S[j]) % F[j] != 0){
                while(now < S[j] || (now - S[j]) % F[j] != 0){
                    now++;
                }
            }
            now += C[j];
            
        }
        cout << now << endl;
    }

    cout << 0 << endl;

}
