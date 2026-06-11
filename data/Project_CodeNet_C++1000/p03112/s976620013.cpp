#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
//constexpr int INF = 1e9;
constexpr ll INF = 1LL << 61;
constexpr int mod = 1e9+7;

ll left_search(ll key, vector<ll>& a){
  int n = a.size();
  int left = -1, right = n;
  while(abs(left-right) > 1){
    int mid = (left+right)/2;
    if(a[mid] <= key){
      left = mid;
    }
    else{
      right = mid;
    }
  }
  return (left==-1 ? -INF : a[left]);
}
ll right_search(ll key, vector<ll>& a){
  int n = a.size();
  int left = -1, right = n;
  while(abs(left-right) > 1){
    int mid =(left+right) /2;
    if(a[mid] >= key){
      right = mid;
    }
    else{
      left = mid;
    }
  }
  return (right == n ? INF : a[right]); 
}
ll calDist(ll a, ll b, ll x){
  if(x <= a && x <= b){
    return abs(max(a, b) - x);
  }
  else if(a <= x && b <= x){
    return abs(x - min(a, b));
  }
  else{
    ll da = abs(x-a), db = abs(x-b);
    return abs(da+db + min(da, db));
  }
}
ll getDist(ll la, ll lb, ll ra, ll rb, ll x){
  ll ans = min(calDist(la, lb, x), calDist(ra, rb, x));
  ans = min(ans, calDist(la, rb, x));
  ans = min(ans, calDist(ra, lb, x));
  return ans;
}
int main(){
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> s(A), t(B);
  REP(i, A){
    cin >> s[i];
  }
  REP(i, B){
    cin >> t[i];
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  while(Q--){
    ll x;
    cin >> x;
    ll la = left_search(x, s), lb = left_search(x, t), ra = right_search(x, s), rb= right_search(x, t);
    ll ans = getDist(la, lb, ra, rb, x);
    cout << ans << endl;        
  }
  return 0;
}
