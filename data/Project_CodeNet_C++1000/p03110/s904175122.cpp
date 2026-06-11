#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;
double X[20];
string U[20];

int main(){
  cin >> N;
  rep(i, N) cin >> X[i] >> U[i];

  double ans;
  rep(i, N){
    if (U[i]=="JPY") ans += X[i];
    else ans += (double) X[i] * 380000;
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
