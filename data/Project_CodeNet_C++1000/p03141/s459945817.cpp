#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<ll> A(N), B(N);
  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }


  vector<pair<ll,int>> C(N);
  for(int i = 0; i < N; i++){
    C[i] = make_pair(A[i] + B[i], i);
  }

  sort(C.rbegin(), C.rend());

  ll a_val = 0;
  ll b_val = 0;
  for(int i = 0; i < N; i++){
    int index = C[i].second;
    // cerr << C[i].first << " " << C[i].second << endl;
    if(i%2==0){
      a_val += A[index];
    } else { 
      b_val += B[index];
    }
  }

  cout << a_val - b_val << endl;

}
