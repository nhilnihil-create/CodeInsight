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
   int N;
   cin>>N;
   vector<int> D(N);
   for(int i=0;i<N;i++){
      cin>>D[i];
   }
   int M;
   cin>>M;
   vector<int> T(M);
   for(int i=0;i<M;i++){
      cin>>T[i];
   }
   map<int,int> count1;
   map<int,int> count2;
   for(int i=0;i<N;i++){
      count1[D[i]]++;
   }
   for(int i=0;i<M;i++){
      count2[T[i]]++;
   }
   for(auto c:count2){
      if(count1[c.first]<c.second){
         cout<<"NO"<<endl;
         return 0;
      }
   }
   cout<<"YES"<<endl;
   return 0;
}