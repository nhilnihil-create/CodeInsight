#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,m;
  cin>>n>>m;
  
  vector<pair<int, int>> v(n);
  
  rep(i,n) {
    pair<int, int> ab;
    cin>>ab.first>>ab.second;
    v[i]=ab;
  }
  
  sort(all(v));
  ll sum=0;
  
  rep(i,n) {
    auto ab=v[i];
    for(int j=1; j<=ab.second; ++j) {
      --m;
      sum += ab.first;
      if(m==0) {
        cout<<sum;
        return 0;
      }
    }
  }
}