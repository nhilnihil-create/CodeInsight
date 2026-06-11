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

    if (k == 0){
        cout << n * n << endl;
        return 0;
    }

    ll cnt = 0;
    REP(x,k+1,n+1){
        ll y = x - k;
        cnt += (n / x) * y;
        ll z = n % x;
        if (z >= k && z != 0) cnt += z - k + 1;
    }

    cout << cnt << endl;
    return 0;
}
