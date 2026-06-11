#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    rep(i, n){
        cin >> a[i];
    }

    sort(ALL(a));
    vector<int> candy(n);

    rep(i, n){
        candy[i] = min(a[i], x);
        x -= candy[i];

        if(i == n - 1){
            candy[i] += x;
        }
    }

    int ans = 0;

    rep(i, n){
        if(a[i] == candy[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}
