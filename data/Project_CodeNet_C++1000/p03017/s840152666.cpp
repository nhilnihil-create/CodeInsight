#include<bits/stdc++.h>
using namespace std;
string S;
bool reach(int start,int goal){
   for(int i=start;i<goal;i++){
      if(S[i]=='#'&&S[i+1]=='#') return false;
   }
   return true;
}
int main(void){
   int N,A,B,C,D;
   cin>>N>>A>>B>>C>>D;
   cin>>S;
   S="#"+S+"#";
   if(!reach(A,C)||!reach(B,D)){
      cout<<"No"<<endl;
      return 0;
   }
   if(C>D){
      bool judge=false;
      for(int i=B;i<=D;i++){
         if(S[i-1]=='.'&&S[i]=='.'&&S[i+1]=='.'){
            judge=true;
         }
      }
      if(!judge){
         cout<<"No"<<endl;
         return 0;
      }
   }
   cout<<"Yes"<<endl;
   return 0;
}
