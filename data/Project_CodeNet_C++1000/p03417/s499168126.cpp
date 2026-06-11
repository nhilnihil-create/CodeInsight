#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll n, m;
    sc(n) sc(m)
    if (n == 1 && m == 1) cout << 1 << endl;
    else if (n == 1 || m == 1) cout << n*m-2 << endl;
    else cout << n*m - 2*n - 2*m + 4 << endl;
    return 0;
}