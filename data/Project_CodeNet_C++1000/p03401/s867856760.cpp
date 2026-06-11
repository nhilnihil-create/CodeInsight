#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  ll N; cin >> N;
  vector<ll> arr(N + 2);
  arr[0] = 0, arr[N -1] = 0;
  rep(i, 1, N + 1) cin >> arr[i];

  vector<ll> acum (N + 2);
  acum[0] = 0;
  rep(i, 1, N + 2){
    acum[i] = abs(arr[i] - arr[i - 1]) + acum[i - 1];
  }

  rep(i, 1, N + 1){
    cout << acum[i - 1] + abs(arr[i - 1] - arr[i + 1]) + abs(acum[N + 1] - acum[i + 1]) << endl;
  }

}
