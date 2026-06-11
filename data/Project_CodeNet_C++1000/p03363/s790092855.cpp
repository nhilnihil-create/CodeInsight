#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;

  map<ll,ll> m;
  m[0] = 1;

  ll sum = 0;
  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    sum += tmp;
    m[sum]++;
  }

  ll ans = 0;
  for(auto x: m){
    ans += x.second * (x.second-1) / 2;
  }
  cout << ans << endl;
}
