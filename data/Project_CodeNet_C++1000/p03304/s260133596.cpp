#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    ll n, m, d;
    cin >> n >> m >> d;

    double ans = ((double)(n-d))*2/(n*n)*(m-1);
  	if(d == 0) ans /= 2;

    cout << fixed << setprecision(10) << ans << endl;
}