#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (1e9)

int main(){
  int n, tl;
  int c, ts;
  cin >> n >> tl;

  int min_cost = INF;

  for(int i = 1; i <= n; i++){
    cin >> c >> ts;
    if(ts <= tl){
      min_cost = min(c, min_cost);
    }
  }

  if(min_cost == INF){
    cout << "TLE" << endl;
  } else {
    cout << min_cost << endl;
  }

  return 0;
}