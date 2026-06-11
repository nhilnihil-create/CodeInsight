#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long l=0,r=1e9+1;
  while (r-l>1){
    long long m = (l+r)/2;
    if(m*m>n) r=m; else l = m;
  }
  cout<<l*l<<endl;
}
