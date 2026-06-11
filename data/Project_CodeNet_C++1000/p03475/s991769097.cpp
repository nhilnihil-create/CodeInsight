#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    ll ans =0;
    vector<ll> C(N),S(N),F(N);
    for(int i=0;i<N-1;i++){
        cin >> C[i] >>S[i] >>F[i];
        
    }
    for(int i=0;i<N;i++){
        ll ans =0;
        for(int j=i;j<N-1;j++){
            if(ans<=S[j]){
                ans = S[j];
            }else{
                ll n= (ans-S[j] +F[j]-1)/F[j];
                ans   = S[j]+F[j]*n;
            }
            ans += C[j];
        }
        cout << ans << endl;
        

    }
    

    return 0;
}