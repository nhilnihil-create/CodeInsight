#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

int
main() 
{
  int N; cin >> N;
  vector<int> arr(N);
  vector<int> arr2(N);
  rep(i, 0, N) cin >> arr[i], arr2[i] = arr[i] - (i + 1);

  sort(arr2.begin(), arr2.end());

  int med_index = N / 2;
  int med = arr2[med_index];
  ll ans = 0;
  rep(i, 0, N){
    ans += abs(arr[i] - (med + i + 1));
  }

  cout << ans << endl;

}

