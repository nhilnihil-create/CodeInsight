#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  if (N == 3) {cout << 2 << " " << 3 << " " << 205 << endl; return 0;}
  
  vector<ll> a;
  for (ll i = 1; i <= 30000; i++) {
    if (i%2==0 || i%3==0 || i%5==0 || i%7==0) {
      a.push_back(i);
    }
  }
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    sum += a[i];
  }
  ll mod = sum%210;
  if (mod%2 == 0) {
    if (a[N-1]%2 == 0) {a[N-1]+=(210-mod);}
    else if (N-2 >= 0 && a[N-2]%2 == 0) {a[N-2]+=(210-mod);}
  } else {
    if (a[N-1]%2 == 1) {a[N-1]+=(210-mod);}
    else if (N-2 >= 0 && a[N-2]%2 == 1) {a[N-2]+=(210-mod);}
    else if (N-3 >= 0 && a[N-3]%2 == 1) {a[N-3]+=(210-mod);}
    else if (N-4 >= 0 && a[N-4]%2 == 1) {a[N-4]+=(210-mod);}
  }
  for (ll i = 0; i < N; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}