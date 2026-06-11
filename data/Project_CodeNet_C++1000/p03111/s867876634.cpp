#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll kadomatsu(ll n,ll ar[],ll a,ll b,ll c,ll suma,ll sumb,ll sumc,ll i){

    if(i==n){
        if( !suma || !sumb || !sumc ){ return INT_MAX;}

        return abs(a-suma)+abs(b-sumb)+abs(c-sumc);
    }

    ll o1=kadomatsu(n,ar,a,b,c,suma,sumb,sumc,i+1);
    ll o2=kadomatsu(n,ar,a,b,c,suma+ar[i],sumb,sumc,i+1)+(suma?10:0);
    ll o3=kadomatsu(n,ar,a,b,c,suma,sumb+ar[i],sumc,i+1)+(sumb?10:0);
    ll o4=kadomatsu(n,ar,a,b,c,suma,sumb,sumc+ar[i],i+1)+(sumc?10:0);

    return min(o1, min(o2, min(o3, o4)));
}

int main() {
    
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll ar[n];

    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }

    ll k=kadomatsu(n,ar,a,b,c,0,0,0,0);
    cout<<k<<endl;
	return 0;
}
