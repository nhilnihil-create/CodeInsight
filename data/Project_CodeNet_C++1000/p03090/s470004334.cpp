#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  int n;
  cin >> n;

  if (n % 2){
    cout << (n - 1) * (n - 3) / 2 + n - 1 << endl;
    for (int i = 1; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        if (i + j != n)
          cout << i << " " << j << endl;
      }
    }
  }
  else {
    cout << (n - 2) * n / 2 << endl;
    for (int i = 1; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        if (i + j != n + 1)
          cout << i << " " << j << endl;
      }
    }
  }



  return 0;
}
