#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>> graph;
bool sort_sec(const pair<int,int> &a,const pair<int,int> &b){
   if(a.second<b.second){
      return true;
   }
   return false;
}
int main(void){
   int N,M;
   cin>>N>>M;
   vector<int> a(M),b(M);
   for(int i=0;i<M;i++){
      cin>>a[i]>>b[i];
   }
   vector<pair<int,int>> land(M);
   for(int i=0;i<M;i++){
      land[i]=make_pair(a[i],b[i]);
   }
   sort(land.begin(),land.end(),sort_sec);
   int now=-1;
   int ans=0;
   for(int i=0;i<M;i++){
      if(land[i].first<=now) continue;
      now=land[i].second-1;
      ans++;
   }
   cout<<ans<<endl;
   return 0;
}