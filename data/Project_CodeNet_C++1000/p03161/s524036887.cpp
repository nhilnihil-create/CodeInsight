/*----------------------------------------------------*
* लेखक --> अमित सिंह
* संस्थान --> राष्ट्रीय प्रौद्योगिकी संस्थान, कुरुक्षेत्र
*-----------------------------------------------------*/
   #include <bits/stdc++.h>
   using namespace std;
   #define ll long long
   #define w(t) int t; cin>>t; while(t--)
   #define fo(i,n) for(int i=0;i<n;i++)
   #define endl "\n" 
   #define MOD 1000000007
   const ll inf=1e18;
   void Tez(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
   }
   ll cache[100001];
   ll fun(int a[],int n,int k){
      if(n==1) return 0;
      if(n<=0) return INT_MAX;
      if(cache[n]!=-1) return cache[n];
      ll ans=INT_MAX;
      for(int i=1;i<=k && i<n;i++){
         ans=min(ans,abs(a[n-1]-a[n-i-1])+fun(a,n-i,k));
      }
      return cache[n]=ans;
   }
   int main(){
      Tez();
      int n,k;
      cin>>n>>k;
      int a[n];
      fo(i,n) cin>>a[i];
      memset(cache,-1,sizeof(cache));
      cout<<fun(a,n,k);
      return 0;
   }

