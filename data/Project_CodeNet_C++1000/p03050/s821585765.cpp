#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main(){
  ll n;
  cin >> n;
  if(n==1 || n==2){
    cout << 0 << endl;
    return 0;
  }
  vector<ll> vec = divisor(n);
  ll sum = 0;
  rep(i, vec.size()){
    ll m = vec[i]-1;
    if(m != 0 && n / m == n/vec[i] && n % m == n/vec[i]) sum += m;
  }
  cout << sum << endl;
  return 0;
}