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

void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
int N,A,B,C;
vector<int> l;
int dfs(int count,int a,int b,int c){
   if(count==N){
      if(a==0||b==0||c==0){
         return 1000000000;
      }else{
         return abs(a-A)+abs(b-B)+abs(c-C);
      }
   }
   int ans=dfs(count+1,a,b,c);
   if(a>=1){
      ans=min(ans,dfs(count+1,a+l[count],b,c)+10);
   }else{
      ans=min(ans,dfs(count+1,a+l[count],b,c));
   }
   if(b>=1){
      ans=min(ans,dfs(count+1,a,b+l[count],c)+10);
   }else{
      ans=min(ans,dfs(count+1,a,b+l[count],c));
   }
   if(c>=1){
      ans=min(ans,dfs(count+1,a,b,c+l[count])+10);
   }else{
      ans=min(ans,dfs(count+1,a,b,c+l[count]));
   }
   return ans;
}
int main(void){
   cin>>N>>A>>B>>C;
   l.resize(N);
   for(int i=0;i<N;i++){
      cin>>l[i];
   }
   cout<<dfs(0,0,0,0)<<endl;
   return 0;
}