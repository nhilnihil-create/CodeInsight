#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

vector<P> prime_factorize(ll n) {
    vector<P> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}


int main() {
  int n;
  cin >> n;
  vector<int>data(n+1);
  rep(i,1,n+1){
    vector<P>prime = prime_factorize(i);
    rep(j,0,prime.size()) data[prime[j].first] += prime[j].second;
  }
  int c3 = 0,c5 = 0,c15 = 0,c25 = 0,c75 = 0;
  rep(i,0,data.size()){
    if(data[i] >= 2) c3++;
    if(data[i] >= 4) c5++;
    if(data[i] >= 14) c15++;
    if(data[i] >= 24) c25++;
    if(data[i] >= 74) c75++;
  }
  ll ans = c5*(c5-1)*(c3-2)/2+c15*(c5-1)+c25*(c3-1)+c75;
  cout << ans << endl;
}