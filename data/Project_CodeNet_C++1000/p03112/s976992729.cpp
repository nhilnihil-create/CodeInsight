#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a+1);
  vector<ll> sr(a+1);
  vector<ll> t(b+1);
  vector<ll> tr(b+1);
  vector<ll> x(q);
  rep(i, a){
    cin >> s[i];
    sr[a-i-1]=-s[i];
  }
  s[a]=INFll;
  sr[a]=INFll;
  rep(i, b){
    cin >> t[i];
    tr[b-i-1]=-t[i];
  }
  t[b]=INFll;
  tr[b]=INFll;
  rep(i, q){
    cin >> x[i];
  }
  rep(i, q){
    ll it1=*upper_bound(s.begin(), s.end(), x[i]);
    ll it2=-*upper_bound(sr.begin(), sr.end(), -x[i]);
    ll it3=*upper_bound(t.begin(), t.end(), x[i]);
    ll it4=-*upper_bound(tr.begin(), tr.end(), -x[i]);
    ll d1[2]={it1, it2};
    ll d2[2]={it3, it4};
    ll ans=INFll;
    ll num;
    rep(j, 2)rep(k, 2){
      num=abs(x[i]-d1[j])+abs(d1[j]-d2[k]);
      ans=min(ans, num);
    }
    rep(j, 2)rep(k, 2){
      num=abs(x[i]-d2[j])+abs(d1[k]-d2[j]);
      ans=min(ans, num);
    }
    cout << ans << endl;
  }

  return 0;
}
