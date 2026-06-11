#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  for(int i=0; i<a; i++){
    cin >> s[i];
  }
  for(int i=0; i<b; i++){
    cin >> t[i];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  for(int i=0; i<q; i++){
    ll x, ans=100000000009;
    cin >> x;
    auto Iter1 = upper_bound(s.begin(), s.end(), x);
    auto Iter2 = upper_bound(t.begin(), t.end(), x);
    int m = Iter1 - s.begin();
    int n = Iter2 - t.begin();
    ll s1, s2, t1, t2;
    if(m!=0) s1 = abs(x-s[m-1]);
    if(m!=a) s2 = abs(x-s[m]);
    if(n!=0) t1 = abs(x-t[n-1]);
    if(n!=b) t2 = abs(x-t[n]);
    if(m!=0&&n!=b) ans = min(ans,s1 + t2 + min(s1,t2));
    if(m!=a&&n!=0) ans = min(ans, s2 + t1 + min(s2,t1));
    if(m!=a&&n!=b) ans = min(ans, max(s2, t2));
    if(m!=0&&n!=0) ans = min(ans, max(s1, t1));
    cout << ans << endl;
  }
  return 0;
}
