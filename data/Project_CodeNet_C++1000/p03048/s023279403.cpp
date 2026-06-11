#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int cnt = 0;
  for(int i = 0; i < N + 1; i++){
    for(int j = 0; j < N + 1; j++){
      if(((N - (R*i + G*j)) % B) == 0 && (N - (R*i + G*j) >= 0))
        cnt++;
    }
  }
  cout << cnt << endl;
}