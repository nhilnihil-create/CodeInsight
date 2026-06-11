#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> a(N), b(N);

  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  for(int i = 0; i < N; i++){
    cin >> b[i];
  }
  ll ans = 0;
  for(int i = 0; i < N; i++){
    if(a[i] - b[i] >= 0){
      ans += a[i] - b[i];
    }
  }
  cout << ans << endl;
}
