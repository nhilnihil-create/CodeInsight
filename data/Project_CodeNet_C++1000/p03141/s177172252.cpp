#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;cin>>n;
  pair<int, int> an[n];
  rep(i,n) {
    cin>>an[i].first>>an[i].second;
  }
  sort(an, an+n, [](auto const& left, auto const& right) {
    return (left.first+left.second) > (right.first + right.second);
  });
  
  ll sum=0;
  rep(i,n) {
    if (i%2==0) sum += an[i].first;
    else sum -= an[i].second;
  }
  cout<<sum<<endl;
}
