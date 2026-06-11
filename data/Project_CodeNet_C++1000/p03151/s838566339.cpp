#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
  }
  vector<ll> B(N);
  REP(i, N) cin >> B[i];
  
  ll a = 0;
  vector<ll> b;
  ll c = 0;
  ll cnt = 0;
  REP(i,N){
    if(A.at(i)<B.at(i)){
      cnt++;
      a+=B.at(i)-A.at(i);
    }else{
      b.push_back(A.at(i)-B.at(i));
      c+=A.at(i)-B.at(i);
    }
  }

  sort(ALL(b));
  reverse(ALL(b));
  // REP(i,b.size()){
  //   cout << b[i] << " ";
  // }
  // cout << endl;
  // cout << a << " " << cnt << endl;
  if(cnt==0){
    cout << 0 << endl;
  }else if(c<a){
    cout << -1 << endl;
  }else{
    REP(i,b.size()){
      if(b.at(i)<a){
        cnt++;
      }
      a-=b.at(i);
    }
    cout << cnt + 1 << endl;
  }
}