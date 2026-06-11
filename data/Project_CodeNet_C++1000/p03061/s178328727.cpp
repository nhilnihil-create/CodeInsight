#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}



int main() {
   fast();
   int n;
   cin>>n;
   int a[n+1];
   int pre[n+1];
   int suf[n+1];
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   if(n==1){
       cout<<mod-7<<"\n";
       return 0;
   }
   pre[1]=a[1];
   suf[n]=a[n];
   for(int i=2;i<=n;i++){
    pre[i]=__gcd(pre[i-1],a[i]);
   }
   for(int i=n-1;i>=1;i--){
      suf[i]=__gcd(a[i],suf[i+1]);
   }
   int ans=0;
   for(int i=1;i<=n;i++){
     if(i>1 && i<=n-1){
       ans=max(__gcd(pre[i-1],suf[i+1]),ans);
     }
     if(i==1){
      ans=max(suf[i+1],ans);
     }
     if(i==n){
      ans=max(pre[i-1],ans);
     }
   }
   cout<<ans<<"\n";


}
