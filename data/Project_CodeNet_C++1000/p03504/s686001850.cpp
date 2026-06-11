#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
   ll N,C,kotae=0;
   cin>>N>>C;
   vector<vector<ll>> v(35,vector<ll> (100010,0));
   vector<ll> ans(100010,0);
   for(ll i=0;i<N;i++){
       ll s,t,c;
       cin>>s>>t>>c;
       v[c][s]++;
       v[c][t+1]--;
   }
   for(ll i=1;i<=C;i++){
       for(ll j=1;j<100010;j++){
           v[i][j]+=v[i][j-1];
        }
   }
   for(ll i=1;i<=C;i++){
       for(ll j=1;j<100010;j++){
           if(v[i][j]) v[i][j]=1;
        }
   }
  
   for(ll i=1;i<=C;i++){
       for(ll j=0;j<100010;j++) ans[j]+=v[i][j];
   }
    for(ll i=1;i<100010;i++) chmax(kotae,ans[i]);
   cout<<kotae<<endl;
}
