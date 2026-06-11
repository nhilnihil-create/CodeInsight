#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<double> a(n);
  double sum = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }

  vector<pair<double, int>> b(n);
  for (int i = 0; i < n; i++){
    b[i] = make_pair(abs(a[i] - sum/n), i);
  }

  sort(b.begin(), b.end());
  
  cout << b[0].second << endl;
  
  

  return 0;
}
