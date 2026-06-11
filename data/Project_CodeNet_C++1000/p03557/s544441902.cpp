#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll>di;


int main()
{
    ll n,s=0;
    cin>>n;
    ll l1[n+1],l2[n+1],l3[n+1];
    for(int i=1;i<=n;i++){
        cin>>l1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>l2[i];
    }
    for(int i=1;i<=n;i++){
        cin>>l3[i];
    }
    sort(l1+1,l1+n+1);
    sort(l2+1,l2+n+1);
    sort(l3+1,l3+n+1);
    //for(int i=1;i<=n;i++){
        ll noi=0,nok=0;
        for(int k=1;k<=n;k++){
//            if(l1[k]<l2[i]&&noi==0)noi=n-k+1;
//            if(l2[i]<l3[k]&&nok==0)nok=n-k+1;
//            if(noi&&nok)break;
              auto it=lower_bound(l1+1,l1+n+1,l2[k]);
              noi=it-(l1+1);//noi-=1;
              auto it2=upper_bound(l3+1,l3+n+1,l2[k]);
              nok=n-(it2-(l3+1));
              //cout<<noi<<" "<<nok<<endl;
              s+=(ll)(noi*nok);
        }

    //}
    cout<<s;
}
