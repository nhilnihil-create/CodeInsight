        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 998244353;


     signed main(){
         cout << std::fixed << std::setprecision(15);
  int n;
  cin>>n;
  int a,ans=0;map<int,int>mp;
  for(int i=0;i<n;i++){
       cin>>a;
       mp[a]++;
  }
  for(auto i:mp){
       if(i.second>=i.first)ans+=i.second-i.first;
       else ans+=i.second;
  }
  cout<<ans<<endl;
 }

 


 






    





      

        
