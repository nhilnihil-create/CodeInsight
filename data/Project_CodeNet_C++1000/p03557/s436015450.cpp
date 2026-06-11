#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
using G = vector<map<int, int>>;

int 
main()
{
  int N; cin >> N;
  vector<int> arr(N), brr(N), crr(N);
  rep(i, 0, N) cin >> arr[i];
  sort(arr.begin(), arr.end());
  rep(i, 0, N) cin >> brr[i];
  sort(brr.begin(), brr.end());
  rep(i, 0, N) cin >> crr[i];
  sort(crr.begin(), crr.end());


  ll ans = 0;
  rep(i, 0, N){
    ll a = lower_bound(arr.begin(), arr.end(), brr[i]) - arr.begin();
    ll c = crr.end() - upper_bound(crr.begin(), crr.end(), brr[i]);
    ans += a * c;
  }

  cout << ans << endl;

}