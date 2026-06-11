#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long gcd(long long a,long long b) {
  if(b==0) return a;
  else return gcd(b,a%b);
}


int main() {
  
  long long X,Y;
  cin >> X >> Y;

  if(X % Y == 0) {
    cout << -1 << endl;
    return 0;
  }

  long long l = X*Y / gcd(X,Y);

  if(l+X > 1000000000000000000) cout << l-X << endl;
  else cout << l+X << endl;
  
}