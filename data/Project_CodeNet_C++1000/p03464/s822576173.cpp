#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){
  int N; cin >> N;

  vector <ll> A(N);
  for (int i = N - 1; i >= 0; i--){
    cin >> A[i];
  }
  
  bool flag = true;

  
  ll M = 2, m = 2;
  for (int i = 0; i < N; i++){
    ll a = M / A[i];
    ll b = m / A[i];
    if (m % A[i] != 0) b++;

    m = b * A[i];
    M = (a + 1) * A[i] - 1;

    if (m > M){
      flag = false;
    }
  }
  
  if (flag == true){
    cout << m << " " << M << endl;
  }else{
    cout << -1 << endl;
  }
    
  
  return 0;
}
