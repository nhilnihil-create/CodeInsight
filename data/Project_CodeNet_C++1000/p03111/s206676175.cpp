#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int N,A,B,C;
int l[8];
int dfs(int k,int a,int b,int c){
  while(k<=N){
  if(k==N){
    if(min(a,min(b,c))>0){
    return abs(a-A)+abs(b-B)+abs(c-C)-30;
    }
    else{
      return 9999999;
    }
  }
    else{
      int w=dfs(k+1,a,b,c);
      int x=dfs(k+1,a+l[k],b,c)+10;
      int y=dfs(k+1,a,b+l[k],c)+10;
      int z=dfs(k+1,a,b,c+l[k])+10;
      return min(min(w,x),min(y,z));
    }
  }
}
int main(){
  cin>>N>>A>>B>>C;
  for(int i=0;i<N;i++){
    cin>>l[i];
  }
  cout<<dfs(0,0,0,0)<<endl;
  return 0;
}