#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pint;

signed main()
{
   int N; cin>>N;
   for(int k=2;k*(k-1)/2<=N;k++){
      if(k*(k-1)/2==N){
         cout<<"Yes"<<endl;
         cout<<k<<endl;
         map<pair<int,int>,int> mp;
         int id=0;
         for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
               id++;
               mp[pint(i,j)]=mp[pint(j,i)]=id;
            }
         }
         for(int i=0;i<k;i++){
            cout<<k-1;
            for(int j=0;j<k;j++){
               if(i==j) continue;
               cout<<' '<<mp[pint(i,j)];
            }
            cout<<endl;
         }
         return 0;
      }
   }
   cout<<"No"<<endl;
   return 0;
}
