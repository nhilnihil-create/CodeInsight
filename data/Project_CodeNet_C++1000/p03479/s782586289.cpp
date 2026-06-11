#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A,B;
  cin>>A>>B;
  int64_t C=B/A,D=2,Z=1;
  while(C>=D){
    D*=2;
    Z++;
  }
  cout<<Z<<endl;
}
