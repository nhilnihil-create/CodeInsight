#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  map<ll, ll> m;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    m[tmp]++;
  }
  ll ans = 0;
  for(auto x: m){
    if(x.second >= x.first){
      ans += x.second - x.first;
    } else { 
      ans += x.second;
    }
  }
  cout << ans << endl;
}

