#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int N;
  cin >> N;
  ll sum = 0;
  rep(i,N){
    int x;
    cin >> x;
    sum += x;
  }
  cout << sum -N << endl;
}
