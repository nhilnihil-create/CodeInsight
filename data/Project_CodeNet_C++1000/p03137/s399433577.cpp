#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M;
  cin >> N >> M;

  if(M == 1){
    cout << 0 << endl;
    return 0;
  }
  if( N >= M){
    cout << 0 << endl;
    return 0;
  }

  vector<ll> v(M);
  for(int i = 0; i < M; i++){
    cin >> v.at(i);
  }
  sort(v.begin(), v.end());

  vector<ll> w(M-1);
  for(int i = 0; i < M-1; i++){
    w[i] = v[i+1] - v[i];
  }

  sort(w.rbegin(), w.rend());

  ll ans = v[v.size()-1] - v[0];

  for(int i = 0; i < N-1; i++){
    ans -= w[i];
  }

  cout << ans << endl;

}
