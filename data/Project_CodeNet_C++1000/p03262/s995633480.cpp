#include<iostream>
#include<vector>
#include<complex>
using namespace std;

long long gcd(long long a, long long b){
    return b != 0 ? gcd(b, a%b) : a;
}
int main(){
  long long n, x;
  cin >> n >> x;
  vector<long long> dx(n);
  for(long long i=0; i < n; i++){
      long long v;
      cin >> v;
      dx[i] = abs(x - v);
  }
  long long ans = dx[0];
  for(long long i=1; i < n; i++){
      ans = gcd(ans, dx[i]);
  }
  cout << ans << endl;
}
