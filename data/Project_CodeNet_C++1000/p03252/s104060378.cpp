#include <bits/stdc++.h>
using namespace std;
int main(){
  int Z=0;
  string S,T;
  cin>>S>>T;
  vector<int> p(26,-1);
  vector<int> q(26,-1);
  int N=S.size();
  for(int i=0;i<N;i++){
    int a=S[i]-'a';
    int b=T[i]-'a';
    if(p[a]==-1&&q[b]==-1){
      p[a]=b;
      q[b]=a;
    }
    else if(p[a]!=b){
      Z=1;
    }
  }

  if(Z==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}