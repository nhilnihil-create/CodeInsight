#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,H,W,A,B,x=0;cin>>N>>H>>W;
  for(int i=0;i<N;i++){
    cin>>A>>B;
    if(H<=A&&W<=B)x++;
  }
  cout<<x<<endl;
}