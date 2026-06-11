#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  int Z=0,X=-1;
  while(N>=10){
    Z+=N%10;
    X+=9;
    N=N/10;
  }
  Z+=N;
  X+=N;
  cout<<max(Z,X)<<endl;
}