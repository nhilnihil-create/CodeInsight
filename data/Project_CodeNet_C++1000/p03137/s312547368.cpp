#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;


vector<pair<double , double> > cor;

int factrial (int n) {
  if(n == 0) return 1;
  else return n*factrial(n-1);
}

int main() {
  int N,M;
  cin >> N >> M;
  int cor[M];
  rep(i,M) {
    cin >> cor[i];
  }
  int dif[N-1];
  sort(cor,cor+M);
  rep(i,M-1) {
    dif[i] = cor[i+1] - cor[i];
  }
  sort(dif,dif+M-1);

  int ans = 0;
  rep(i,M-N) {
    ans += dif[i];
  }
  cout << ans << endl;

  return 0;
}








