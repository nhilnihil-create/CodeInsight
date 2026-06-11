#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll X, Y;
    cin >> X >> Y;
    vector<ll> out;
    ll tmp = X;
    while (true) {
      out.push_back(tmp);
      tmp *= 2;
      if (tmp > Y) break;
    }
    cout << out.size() << endl;
    return 0;
}