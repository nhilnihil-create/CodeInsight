#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second

typedef pair<lint, lint> P;
const lint MOD = 1e9+7;
const lint INF = MOD * MOD;
const int MAX = 100005;

int main(){
    int n, k; cin >> n >> k;
    lint a = 0;
    for(int b = k + 1; b <= n; b++){
        int p = n / b, q = n % b;
        if(q >= k && k != 0) a += (q - k + 1);
        if(q > k && k == 0) a += q;
        a += (b-k) * p;
    }
    cout << a << endl;
}
