        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200002;
const int MOD =1000000007;

     signed main(){
        int n;
        cin>>n;
       string s[n],x="MARCH";
       for(int i=0;i<n;i++)cin>>s[i];
       int k[5]={},ans=0;
       for(int i=0;i<n;i++)for(int j=0;j<5;j++)if(s[i][0]==x[j])k[j]++;
       for(int i=0;i<5;i++)for(int j=i+1;j<5;j++)for(int ii=j+1;ii<5;ii++)ans+=k[i]*k[j]*k[ii];
       cout<<ans<<endl;

   }
     


 


 






    





      

        
