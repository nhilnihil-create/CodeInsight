#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  int white,total;
  total=H*W;
  white=total-(H*w+h*W-h*w);
  cout<<white<<endl;
}
