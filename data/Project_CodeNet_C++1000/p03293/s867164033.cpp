#include<bits/stdc++.h>
using namespace std;
int main(){
  string S; string T;
  cin>>S>>T;
  int K=0;
  int L=S.size();
  if(S==T)
    K++;
  for(int i=0; i<L-1; i++){
    S=S.back()+S.substr(0,S.size()-1);
   if(S==T)
     K++;
    else continue;
  }
  if(K==0)
    cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}