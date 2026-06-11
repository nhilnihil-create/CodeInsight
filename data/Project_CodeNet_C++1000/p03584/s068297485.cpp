#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

   ll n,k;
   cin>>n>>k;
   ll a[n],b[n];
   ll ans = 0;
   for(int i=0;i<n;i++){
       cin>>a[i]>>b[i];
       if((a[i] | k) <= k) ans += b[i]; 
   }
   //cerr<<ans<<endl;
   for(int bit = 0; bit < 33; bit++){
       ll ret = 0;
       if(!(k&(1LL<<bit))) continue;
       for(int i=0;i<n;i++){
           bool pos = true;
           for(int j=bit+1;j<33;j++){
               if(!(k&(1LL<<j)) && (a[i]&(1LL<<j))){
                   pos = false;
                   break;
               }
           }
           if(pos && a[i]<=k && !(a[i]&(1LL<<bit))){
               ret += b[i];
           }
       }
       ans = max(ans,ret);
      // cerr<<bit<<" "<<ans<<endl;
   }
   cout<<ans<<endl;

   
}