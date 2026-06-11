#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<ll> v(N);
  for(int i = 0; i < N; i++){
    cin >> v.at(i);
  }

  vector<ll> left(N), right(N);
  left[0] = abs(v[0]);
  right[N-1] = abs(v[N-1]);

  for(int i = 1; i < N; i++){
    left[i] = abs(v[i] - v[i-1]) + left[i-1];
  }
  for(int i = N-2; i >= 0; i--){
    right[i] = abs(v[i] - v[i+1]) + right[i+1];
  }

  ll ans = 0;
  for(int i = 0; i < N; i++){
    if(i == 0){
      ans = right[1] + abs(v[1]);
    } else if(i == N-1){
      ans = left[N-2] + abs(v[N-2]);
    } else { 
      ans = left[i-1] + abs(v[i+1] - v[i-1]) + right[i+1];
    }
    cout << ans << endl;
  }
}
