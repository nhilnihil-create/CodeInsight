#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5) + 5;
#define REP(i, n) for (int i = 0; i < n; i++)

ull n, x, cum[MAX_N]{};

int main() {
    cin >> n >> x;
    ull a;
    REP(i,n){
        cin >> a;
        cum[i+1] += cum[i]+a;
    }
    ull ans = LLINF;
    for(ull i=1;i<=n;i++){
        ull tmp = 5*cum[n], k = n-i;
        while(1){
            if(k<=i)break;
            k -= i;
            tmp += 2*cum[k];
        }
        tmp += (n+i)*x;
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
