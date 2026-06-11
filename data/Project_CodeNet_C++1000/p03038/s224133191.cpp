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
  vector<pii> A(N+M); 
  rep(i,N) {
    cin >> A[i].first;
    A[i].second = 1;
  }
  rep(i,M) cin >> A[N+i].second >> A[N+i].first;
  sort(all(A));
  reverse(all(A));
  int cnt = 0;
  ll ans = 0;
  rep(i,M+N) {
    int b = A[i].second;
    ll c = A[i].first;
    cnt += b;
    ans += c*b;
    if (cnt>N){
      ans -= c*(cnt-N);
      break;
    }    
  }
  cout << ans << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
