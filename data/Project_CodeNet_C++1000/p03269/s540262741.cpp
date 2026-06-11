        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 1000001;
const int MOD =1000000007;
const int INV2 = (MOD+1)/2;



     signed main(){
     int l,n=20,m=0;
     cin>>l;
      vector<pair<int,int>> hen[n];
      if((l>>19)){
        hen[0].push_back(make_pair(1,(1ll<<18)));
        hen[0].push_back(make_pair(1,0));
      }
      if(l&(1ll<<(18)))hen[0].push_back(make_pair(1,(l>>(19))<<(19)));
      for(int i=1;i<n-1;i++){
        hen[i].push_back(make_pair(i+1,(1ll<<(18-i))));
        hen[i].push_back(make_pair(i+1,0));
        if(l&(1ll<<(18-i)))hen[0].push_back(make_pair(i+1,(l>>(19-i))<<(19-i)));
      }
      for(int i=0;i<n;i++)m+=hen[i].size();
      cout<<n<<' '<<m<<endl;
      for(int i=0;i<n;i++){
        for(auto&& j : hen[i]){
          cout<<i+1<<' '<<j.first+1<<' '<<j.second<<endl;
        }
      }




        





}


        
