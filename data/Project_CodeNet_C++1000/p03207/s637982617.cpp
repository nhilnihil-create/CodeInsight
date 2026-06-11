#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Z=0,A=0;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    Z+=a;
    A=max(A,a);
  }
  cout<<Z-A/2<<endl;
}