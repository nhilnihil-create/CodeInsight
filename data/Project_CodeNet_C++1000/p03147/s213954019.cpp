#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
  ll N;
  cin >> N;
  vector<ll> h(N);
  for (int i = 0; i < N; i++) cin >> h[i];

  ll out = 0;
  bool check = true;
  while (check) {
    int i = 0;
    check = false;
    while (i < N) {
      if(h[i]>0){
        out++;
        check = true;
        for (i; h[i] > 0; i++) h[i]--;
      }
      i++;
    }
  }
  cout << out << endl;
  return 0;
}