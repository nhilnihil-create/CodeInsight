#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i <= (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    int A,B,C,X;cin>>A>>B>>C>>X;
    int ans=0;
    rep(i,A){
        rep(j,B){
            rep(k,C){
                if(500*i+100*j+50*k==X){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}