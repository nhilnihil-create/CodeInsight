#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll t[100005],x[100005],y[100005];
int main(void){
    cin>>n;
    t[0]=0; x[0]=0; y[0]=0;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>x[i]>>y[i];
        if(t[i]-t[i-1]<(abs(x[i]-x[i-1])+abs(y[i]-y[i-1]))||(x[i]+y[i])%2!=((x[i-1]+y[i-1]+t[i]-t[i-1])%2)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    
}
