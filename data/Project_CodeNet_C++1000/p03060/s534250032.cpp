#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll v[25],c[25],d[25];
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
        d[i]=v[i]-c[i];
    }
    sort(d,d+n);
    for(int i=0;i<n;i++){
        if(d[i]>0){
            ans+=d[i];
        }
    }
    cout<<ans<<endl;

}
