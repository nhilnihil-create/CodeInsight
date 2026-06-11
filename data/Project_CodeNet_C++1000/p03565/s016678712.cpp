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
   string S,T;
   cin>>S>>T;
   int N=S.size();
   int M=T.size();
   string ans="-";
   for(int i=0;i<=N-M;i++){
      string S2=S;
      bool flag=true;
      for(int j=0;j<M;j++){
         if(S[i+j]!='?'&&S[i+j]!=T[j]){
            flag=false;
         }
         S2[i+j]=T[j];
      }
      if(flag){
         replace(S2.begin(),S2.end(),'?','a');
         ans=S2;
      }
   }
   if(ans=="-"){
      cout<<"UNRESTORABLE"<<endl;
   }else{
      cout<<ans<<endl;
   }
   return 0;
}