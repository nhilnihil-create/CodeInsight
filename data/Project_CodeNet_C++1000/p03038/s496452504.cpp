#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  long long n;
  long long m;
  const long long max_n = 1e5;
  long long a[max_n + 1];
  pair<long long, long long> ope[max_n + 1];

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int j = 0; j < m; j++){
    cin >> ope[j].second >> ope[j].first;
  }
  sort(a, a+n);
  sort(ope, ope+m, greater<>());

  long long sum = 0;
  long long i = 0;
  long long f = 0;
  long long last_c = 0;
  for(int j = 0; j < m; j++){
    long long b, c;
    b = ope[j].second;
    c = ope[j].first;

    f = i + b - 1;
    if(f >= n) f = n - 1;
    // if(f < 0) break;

    if(a[f] < c) {
      sum += (f - i + 1) * c;
      i += b;
    }else{
      last_c = c;
      break;
    }

    if(f == n - 1) break;
  }

  for(int j = i; j < n; j++){
    if(a[j] < last_c) sum += last_c;
    else sum += a[j];
  }

  cout << sum << endl;

  return 0;
}