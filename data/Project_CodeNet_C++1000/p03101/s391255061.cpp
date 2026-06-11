#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  int white=H*W;
  white-=h*W+w*(H-h);
  cout<<white<<endl;
  
  
}