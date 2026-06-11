#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  int sal[26],tal[26];
  for(int i=0;i<26;i++){
    sal[i]=-1; tal[i]=-1;
  }
  int judge=0;
  for(int i=0;i<S.size();i++){
    int x=(char)S[i]-'a';
    int y=(char)T[i]-'a';
    if(sal[x]==-1||sal[x]==y){
      if(tal[y]==-1||tal[y]==x){
        sal[x]=y; tal[y]=x;
      }
      else{
        judge++;
        break;
      }
    }
    else{
      judge++;
      break;
    }
  }
  if(judge==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}