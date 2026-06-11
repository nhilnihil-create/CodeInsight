#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
ll Lucas(int N){
  if (N == 0) return 2;
  else if (N == 1) return 1;
  else return Lucas(N - 1) + Lucas(N - 2);
}
*/

int main(void){
  int N;
  cin >> N;

  vector <ll> L(87);
  L.at(0) = 2;
  L.at(1) = 1;
  if (N == 1) cout << L.at(1) << endl;
  else{
    for (int i = 2; i <= N; i++){
      L.at(i) = L.at(i - 2) + L.at(i - 1);
    }
    cout << L.at(N) << endl;
  }
}
