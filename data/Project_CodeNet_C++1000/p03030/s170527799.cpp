#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    int n;
    cin >> n;

    vector<tuple<string, int, int>> rs(n);
    for (int i = 0; i < n; ++i) {
        cin >> get<0>(rs[i]) >> get<1>(rs[i]);
        get<1>(rs[i]) *= -1;
        get<2>(rs[i]) = i + 1;
    }
    sort(rs.begin(), rs.end());
    for(const auto x : rs){
        cout << get<2>(x) << endl;;
    }
}
