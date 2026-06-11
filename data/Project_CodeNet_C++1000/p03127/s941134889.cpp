#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int 
main() {

  ll N; cin >> N;
  vector<int> arr(N);
  rep(i, 0, N) cin >> arr[i];

  sort(arr.begin(), arr.end());
  while(arr.size() >= 2){
    for(ll i = 1; i < arr.size(); i++){
      arr[i] = arr[i] % arr[0];
    }
    sort(arr.begin(), arr.end());
    arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
  }

  cout << arr[0] << endl;


}
