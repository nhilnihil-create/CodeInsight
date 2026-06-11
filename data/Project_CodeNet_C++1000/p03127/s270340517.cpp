#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A;
  cin>>N>>A;
  for(int i=0;i<N-1;i++){
    int a;
    cin>>a;
    A=gcd(a,A);
  }
  cout<<A<<endl;
}
