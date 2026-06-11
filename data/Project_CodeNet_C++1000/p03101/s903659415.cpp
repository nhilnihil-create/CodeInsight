#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll H,W,h,w;
  cin>>H>>W>>h>>w;
  cout<<H*W-h*W-H*w+h*w<<endl;
  return 0;
}
