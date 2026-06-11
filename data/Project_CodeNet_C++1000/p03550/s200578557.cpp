#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Z,W;
  cin>>N>>Z>>W;
  int a[N];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int ans=0;
  
  //N=1のとき
  if(N==1){
    ans=abs(a[0]-W);
    cout<<ans<<endl;
    return 0;
  }
  
  //N>1のとき
  int x1,x2,y1,y2;
  x1=a[N-2];
  y1=a[N-1];
  x2=a[N-1];
  y2=W;
  if(abs(x1-y1)>abs(x2-y2)){
    ans=abs(x1-y1);
  }
  else{
    ans=abs(x2-y2);
  }
  cout<<ans<<endl;
  return 0;
}
