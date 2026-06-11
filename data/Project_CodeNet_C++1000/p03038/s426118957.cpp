#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, M; cin >> N >> M;
  int  A[N]; rep(i,N) cin >> A[i];
  sort(A, A+N);

  vector<pii> v(M);
  rep(i,M) cin >> v[i].second >> v[i].first;
  sort(all(v));
  reverse(all(v));

  int prev=0, now = 0;
  ll ans = 0;
  rep(i,M){
    ll C = v[i].first;
    int B = v[i].second;
    now = lower_bound(A+prev, A+N, C) - A;
    now = prev + min(B,now-prev);
    ans +=  (now-prev)*C;
    // cout << now << endl;
    prev = now;
  }
  for (int i=now;i<N;i++){
    ans += A[i];
  }
  cout << ans << endl;



  // cout << fixed << setprecision(10);
  
  return 0;
}
