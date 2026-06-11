#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int A[n];
  int m=1000000000,M=0;
  for (int i = 0; i < n; i++) {
    cin>>A[i];
    if(m>A[i])m=A[i];
    if(M<A[i])M=A[i];
  }
  cout<<M-m<<endl;

}
