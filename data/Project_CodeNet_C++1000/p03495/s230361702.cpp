        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200002;
const int MOD =1000000007;


   
     signed main(){
 int n,k,a,z[200001]={},ans=0;
 cin>>n>>k;
 for(int i=0;i<n;i++){
     cin>>a;
     z[a]++;
 }
 sort(z,z+200001);
 for(int i=0;i<200001-k;i++)ans+=z[i];
 cout<<ans<<endl;
   }
     


 


 






    





      

        
