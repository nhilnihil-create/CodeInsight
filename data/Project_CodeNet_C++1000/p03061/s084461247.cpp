#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

template<typename T>
T gcd(T a, T b) {
  if(a < b) swap(a,b);
    
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> v(N), a(N), b(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
    a[i] = v[i];
    b[i] = v[i];
  }


  for(int i = 0; i < N; i++){
    if(i == 0){
      continue;
    } else { 
      a[i] = gcd(a[i], a[i-1]);
    }
  }

  for(int i = N -1; i >= 0; i--){
    if(i == N-1){
      continue;
    } else { 
      b[i] = gcd(b[i], b[i+1]);
    }
  }

  ll max_val = 0;
  for(int i = 0; i < N; i++){
    if(i==0){
      max_val = max(max_val, b[i+1]);
    } else if(i == N-1){
      max_val = max(max_val, a[i-1]);
    } else { 
      max_val = max(max_val, gcd(a[i-1], b[i+1]));
    }
  }
  cout << max_val << endl;
}
