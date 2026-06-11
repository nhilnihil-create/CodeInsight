#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int
main() 
{
  int N, M; cin >> N >> M;
  vector<int> arr(M);
  rep(i, 0, M) cin >> arr[i];
  sort(arr.begin(), arr.end());
  vector<int> diff(M - 1);

  if(M == 1 || N >= M){
    cout << 0 << endl;
    return 0;
  }else if(M == 2){
    cout << abs(arr[1] - arr[0]) << endl;
    return 0;
  }

  vector<int> original(M - 1);
  rep(i, 0, M - 1){
    int tmp =  arr[i + 1] - arr[i];
    diff[i] = tmp;
    original[i] = tmp;
  }
  
  sort(diff.begin(), diff.end(), greater<int>());

  vector<int> positions(N -1);
  rep(i, 0, N - 1){
    auto index = find(original.begin(), original.end(), diff[i]);
    positions[i] = distance(original.begin(), index);
  }
  
  int ans = *(arr.end() - 1) - *arr.begin();
  rep(i, 0, N - 1){
    ans -= original[positions[i]];
  }

  cout << ans << endl;

}


