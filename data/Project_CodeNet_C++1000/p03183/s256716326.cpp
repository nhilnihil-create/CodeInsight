#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAXN = 1111;
const int MAXW = 21111;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n;
int w[MAXN], s[MAXN], v[MAXN];
ll ans[MAXW];
bool comp(int i, int j) { //comparator to sort elements
  return s[i] + w[i] < s[j] + w[j];
}
int main(){ // we may put w[i] on top of some s[i]
  cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0;i<n;i++) cin >> w[i] >> s[i] >> v[i];
  vector<int> items(n);
  iota(items.begin(), items.end(),0);
  sort(items.begin(),items.end(), comp);
  for(int j=20000;j;j--) {
    ans[j] = -INF;
  }
  for(auto i : items) {
    //cerr << "@ " << i <<endl;
    for(int j=s[i];j>=0;j--) {
      if (j+w[i] <= 20000) ans[j+w[i]] = max(ans[j+w[i]], ans[j] + v[i]);
    }
  }
  ll bestans = 0;
  for(int j=20000;j;j--) {
    bestans = max(bestans, ans[j]);
  }
  cout << bestans <<endl;
}
