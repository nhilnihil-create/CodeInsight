#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define PI 3.14159265359
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
  ll N;
  cin >> N;
  ll A[N-1],B[N-1],C[N];
  vector<vector<ll>> v(N+1);
  ll ans = 0;
  vector<bool> visited(N+1, false);

  FOR(i,0,N-2){
    cin >> A[i] >> B[i];
    v[A[i]].PB(B[i]);
    v[B[i]].PB(A[i]);
  }
  FOR(i,0,N-1){
    cin >> C[i];
    ans += C[i];
  }
  sort(C,C+N,greater<ll>());
  ans -= C[0];

  queue<ll> que;
  que.push(1);
  ll output[N+1];
  ll ref = 0;

  while(que.size()>0){
    ll now = que.front(); que.pop();
    if(visited[now]) break;

    output[now] = C[ref];
    ++ref;
    visited[now] = true;
    for(ll x: v[now]){
      if(!visited[x]) que.push(x);
    }
  }

  cout << ans << endl;
  FOR(i,1,N) cout << output[i] << " ";
  cout << endl;




}

