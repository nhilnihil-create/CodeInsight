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
   void Tez(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
   }
   int main(){
      Tez();
      int n,k;
      cin>>n>>k;
      int ans=1;
      fo(i,n){
         if(ans*2<=ans+k){
            ans=ans*2;
         }else{
            ans+=k;
         }
      }
      cout<<ans;
      return 0;
   }

