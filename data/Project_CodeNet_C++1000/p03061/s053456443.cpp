#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
  if(b == 0){
    return a;
  }
  return gcd(b, a%b);
}

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);

    for(long long i = 0; i < n; i++) cin >> a[i];

    vector<long long> left(n+1, 0), right(n+1, 0);
    for(long long i = 0; i < n; i++) left[i+1] = gcd(left[i], a[i]);
    for(long long i = n-1; i >= 0; i--) right[i] = gcd(right[i+1], a[i]);

    long long ans = 0;
    for(long long i = 0; i < n; i++){
        long long l = left[i];
        long long r = right[i+1];

        if(ans < gcd(l, r)) ans = gcd(l, r);
    }

    cout << ans << endl;
    return 0;
}