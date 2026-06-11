#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
using Data = pair<ll, vector<int>>;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<int> num = {x, y, z};
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  priority_queue<Data> pq;
  set<Data> st;

  auto add = [&](Data d) {
    int s = d.second[0];
    int t = d.second[1];
    int u = d.second[2];
    rep(i, 3) {
      vector<int> soeji({s, t, u});
      soeji[i]++;
      if(soeji[i] >= num[i]) continue;
      ll sum = a[soeji[0]] + b[soeji[1]] + c[soeji[2]];
      Data d = Data(sum, soeji);
      if(!st.count(d)) st.insert(d), pq.push(d);
    }
  };
  ll sum = a[0] + b[0] + c[0];
  pq.push(Data(sum, vector<int>(3, 0)));
  st.insert(Data(sum, vector<int>(3, 0)));

  rep(i, k) {
    Data d = pq.top(); pq.pop();
    cout << d.first << endl;
    add(d);
  }
}