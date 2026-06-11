#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e4 + 150;

int can[N];
bool dig[10];
int c[10] = {0,2,5,5,4,5,6,3,7,6};
int pv[N];

int main(){
  fastIO;
  for(int i = 0 ; i < N ; i++ ) can[i] = -1;
  int n, m;
  cin >> n >> m;
  int d;
  for(int i = 1; i <= m ; i ++ ){
    cin >> d;
    dig[d] = true;
  }
  can[0] = 0;
  for(int i = 0 ; i <= n; i ++ ){
    if(can[i] == -1) continue;
    for(int j = 1; j < 10 ; j ++ ){
      if(dig[j]){
        if(can[i + c[j]] < can[i] + 1){
          can[i + c[j]] = can[i] + 1;
          pv[i + c[j]] = j;
        }
        else if(can[i + c[j]] == can[i] + 1){
          pv[i + c[j]] = max(pv[i + c[j]], j);
        }
      }
    }
  }
  while(n > 0){
    cout << pv[n];
    n -= c[pv[n]];
  }
  return 0;
}