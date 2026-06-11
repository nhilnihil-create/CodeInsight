#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll H,W,h,w;
  cin>>H>>W>>h>>w;
  cout<<H*W-W*h-w*H+h*w<<endl;
}