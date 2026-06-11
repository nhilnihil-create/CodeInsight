#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    Int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<Int> x(N), y(M);
    rep(i,N) cin >> x[i];
    rep(j,M) cin >> y[j];
  
    sort(x.begin(),x.end(),greater<Int>());
    sort(y.begin(),y.end());
  
    bool flag = true;
    if (X >= Y) flag = false;
    if (x[0] >= y[0]) flag = false;
    if (x[0] >= Y) flag = false;
    if (X >= y[0]) flag = false;
  
    if (flag) cout << "No War" << endl;
    else cout << "War" << endl;
}
