#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll N;
  cin >> N;
  
  ll h, n, w;
  for (int i = 0; i < 3501; i++){
    for (int j = 0; j < 3501; j++){
      ll e = N*i*j;
      ll d = 4*i*j - N*i - N*j;
      if (d > 0 && e % d == 0){
        h = i;
        n = j;
        w = e / d;
        break;
      }
    }
  }


  cout << h << " " << n << " " << w << endl;
  

  return 0;
}
