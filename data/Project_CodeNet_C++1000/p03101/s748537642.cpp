#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  int sum=H*W;
  int minus=W*h+H*w-h*w;
  cout<<sum-minus<<endl;
}
