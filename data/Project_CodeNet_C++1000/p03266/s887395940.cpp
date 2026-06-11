#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod = 1e9+9;
const int INF = 1e9;

int main(){
    ll n, k;
    cin >> n >> k;

    if (k % 2 == 1){
        ll m = n / k;
        m = pow(m, 3);
        printf("%lld\n", m);
        return 0;
    }
    else {
        ll m = n / k;
        m = pow(m, 3);
        ll o = 0;
        REP(i,1,n+1){
            if (i % k == (k / 2)) o++;
        }
        //cout << m << endl;
        //cout << o << endl;
        o = pow(o, 3);
        printf("%lld\n", m+o);
        return 0;
    }
}
