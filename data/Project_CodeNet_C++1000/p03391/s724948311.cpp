#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n;
    cin>>n;
    ll a[n],b[n];
    ll ans=0;
    bool pos=false;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(a[i]!=b[i])pos=true;
        ans+=a[i];
    }
    
    if(!pos){
        cout<<0<<endl;
        return 0;
    }

    ll t=1e10,p=-1;
    for(int i=0;i<n;i++){
        if(a[i]>b[i] && t>b[i]){
            t=b[i];
            p=i;
        }
    }
    ans-=b[p];
    
    cout<<ans<<endl;




}
