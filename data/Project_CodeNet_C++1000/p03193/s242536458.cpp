#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ll N,H,W;
    cin>>N>>H>>W;
    ll ans=0;
    vector<ll>A(N);
    vector<ll>B(N);
    rep(i,N){
        cin>>A[i];
        cin>>B[i];
        ans+=min(A[i]/H,B[i]/W);
    }
    cout<<ans<<endl;
}
