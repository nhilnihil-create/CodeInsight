#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N; cin >> N;
    set<ll> S;
    rep(i, N) {
        ll tmp; cin >> tmp;
        S.insert(tmp);
    }
    cout << S.size() << endl;


}
