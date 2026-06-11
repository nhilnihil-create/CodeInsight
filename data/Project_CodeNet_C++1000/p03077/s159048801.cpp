#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N,A[5];cin>>N;
    ll ans = -1;
    for(int i=0;i<5;i++) {
        ll c;cin>>c;
        ll t=(N%c==0)?N/c+i:N/c+i+1;
        ans=max(ans+1,t);
    }
    cout<<ans<< "\n";
}