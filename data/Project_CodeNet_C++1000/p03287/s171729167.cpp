#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N,M;
  cin >> N >> M;
  vector<ll> v(N);
  map<int,ll> m;
  for(int i = 0; i < N; i++){
    cin >> v.at(i);
    v.at(i) %= M;

    if(i > 0){
      v.at(i) += v.at(i-1);
      v.at(i) %= M;
    }

    if(m.count(v.at(i)) == 0){
      m[v.at(i)] = 1;
    } else { 
      m[v.at(i)]++;
    }
  }

  ll ans = 0;
  for(auto x: m){
    if(x.first == 0){
      ans += x.second;
    }

    ans += x.second * (x.second -1) / 2;

  }
  cout << ans << endl;

}
