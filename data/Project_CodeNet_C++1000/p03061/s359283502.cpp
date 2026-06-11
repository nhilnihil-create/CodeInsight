#include <iostream>
using namespace std;

int gcd(int x, int y) {if (y == 0) return x; return gcd(y,x%y);}

int main(){
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  int b[n]; b[0] = a[0];
  int c[n]; c[n-1] = a[n-1];
  for(int i=1;i<n;i++) {
    b[i] = gcd(b[i-1], a[i]);
  }
  for(int i=n-2;i>=0;i--) {
    c[i] = gcd(c[i+1], a[i]);
  }
  int an = max(c[1], b[n-2]);
  for(int i=0;i<n;i++) {
    an = max(an, gcd(b[i-1], c[i+1]));
  }
  cout<<an<<endl;
}