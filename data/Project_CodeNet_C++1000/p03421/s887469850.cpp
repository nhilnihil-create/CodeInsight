#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
typedef vector<lint> poly;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const lint mod = 1e9+7;
const lint INF = mod*mod;
const int MAX =100010;

int main(){
    lint n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    if(a+b-1>n || a*b<n){
        printf("-1\n");
        return 0;
    }
    if(b==1){
        rep(i, n) printf("%d ", i+1);
        return 0;
    }
    lint t=a*b-n;
    lint q=t/(b-1), r=t%(b-1), s=q+b-r;
    int p[n], cur=1;
    rep(i, q) p[i]=cur++;
    rFor(i, s, q) p[i]=cur++;
    rep(i, (n-s)/b)rFor(j, s+(i+1)*b, s+i*b) p[j]=cur++;
    rep(i, n) printf("%d ", p[i]);
}
