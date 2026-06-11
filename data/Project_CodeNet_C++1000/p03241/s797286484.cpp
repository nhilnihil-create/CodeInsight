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
  ll n, m;
  cin >> n >> m;
  vector<ll> divisors = divisor(m);
  ll smallest = 1000000000000;
  for(int i=0; i<divisors.size(); i++){
    if(divisors[divisors.size()-1-i] < n){
      break;
    }
    smallest = divisors[divisors.size()-1-i];
  }
  cout << m/smallest << endl;
  return 0;
}


