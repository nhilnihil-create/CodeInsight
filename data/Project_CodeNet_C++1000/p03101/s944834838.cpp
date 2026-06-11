#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W,A,B;
  cin>>H>>W>>A>>B;
  cout<<H*W-A*W-B*H+A*B<<endl;
}