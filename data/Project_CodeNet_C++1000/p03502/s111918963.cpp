#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
  llong N;
  cin >> N;
  llong sum = 0;
  llong M = N;
  for(int i=0; i<9; ++i){
    sum += M % 10;
    M /= 10;
  }
  if(N%sum == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}