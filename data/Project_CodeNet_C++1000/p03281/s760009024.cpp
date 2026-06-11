#include <iostream>
using namespace std;
int main() {
  int n,a=0; cin>>n;
  for(int i=1; i<=n; i++){
    int c=0;
    for(int j=1; j<=i; j+=2) if(i%j==0) c++;
    if(c==8) a++; 
  }
  cout<<a;
}