#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int
GCD(int x, int y)
{
  return y ? GCD(y, x % y) : x;
}

int 
main() {
  int N; cin >> N;
  vector<int> arr(N);
  rep(i, 0, N) cin >> arr[i];

  if(N == 2){
    int maxi = max(arr[0], arr[1]);
    cout << maxi << endl;
    return 0;
  }

  vector<int> left(N);
  left[0] = arr[0];
  rep(i, 0, N - 1){
    left[i + 1] = GCD(left[i], arr[i + 1]);
  }

  vector<int> right(N);
  right[0] = arr[N - 1];
  rep(i, 0, N - 1){
    right[i + 1] = GCD(right[i], arr[N - 2 - i]);
  }

  int ans = right[N - 2];
  rep(i, 0, N){
    int comp = GCD(left[i], right[N - i - 3]);
    if(ans < comp) ans = comp;
  }

  int comp = GCD(ans, left[N - 2]);
  if(ans < comp) ans = comp;

  cout << ans << endl;

}
