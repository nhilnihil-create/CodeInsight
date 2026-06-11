#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    int a[n], sum = 0;
    rep(i, n){
        scanf("%d", &a[i]);
        sum += a[i];
    }

    bitset<2010*2010> bs;
    bs[0] = 1;
    rep(i, n) bs |= (bs << a[i]);

    rep(i, 2010*2010)if(bs[i] && i >= (sum+1)/2){
        printf("%d\n", i);
        return 0;
    }
}