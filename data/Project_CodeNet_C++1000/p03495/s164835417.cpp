#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  ll N, K;
  cin >> N >> K;
  map<ll, ll> A;
  for (int i = 0; i < N; i++){
    ll tmp = 0;
    cin >> tmp;
    A[tmp]++;
  }
  if(A.size()<=K){
      cout << 0 <<endl;
      return 0;
  }
  vector<ll> sum;
  for(auto i : A){
      sum.push_back(i.second);
  }
  sort(sum.begin(), sum.end());
  ll dif = A.size() - K;
  ll cnt = 0;
  for (int i = 0;i<dif; i++) {
    cnt += sum[i];
  }
  cout << cnt << endl;
  return 0;
}