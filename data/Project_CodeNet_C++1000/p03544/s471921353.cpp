#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t x, y;
  x=2;
  y=1;
  int N;
  cin>>N;
  for(int i=2;i<=N;i++){
    if(i%2==0) x=x+y;
    else y=x+y;
  }
  if(N%2==0) cout<<x<<endl;
  else cout<<y<<endl;
}
