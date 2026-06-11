#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, i, Num=0;
  string S;
  cin>>N>>S;
  for(i=0; i<N; i++)if(S[i]=='E')Num++;
  int mn=Num;
  
  for(i=0; i<N; i++){
    if(S[i]=='E')Num--;
    if(S[i]=='W')Num++;
    mn=min(mn, Num);
  }
  cout<<mn<<endl;
  return 0;
}