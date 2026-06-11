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
  vector<llong> L(87, 0);
  L[0] = 2;
  L[1] = 1;
  for(int i=2; i<=86; ++i){
    L[i] = L[i-1] + L[i-2];
  }
  int N;
  cin >> N;
  cout << L[N] << endl;
}