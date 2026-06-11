#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

double f(double x, int l, int r, int v){
    if(x <= l) return v+(l-x);
    else if(x <= r) return v;
    return v+(x-r);
}

int main(){
    int N; cin >> N;
    vector<int> t(N+2, 0), v(N+2, 0), l(N+2, 0), r(N+2, 0);

    for(int i=1; i<=N; i++) cin >> t[i];
    for(int i=1; i<=N; i++) cin >> v[i];

    for(int i=1; i<=N; i++){
        r[i] = r[i-1] + t[i];
        l[i] = r[i-1];
    }

    r[N+1] = r[N];
    l[N+1] = r[N];

    double h1 = 0.0;
    double h2;
    double ans = 0.0;

    for(double x=0.5; x<=r[N]; x+=0.5){
        h2 = 500.0;
        for(int i=0; i<N+2; i++) h2 = min(h2, f(x, l[i], r[i], v[i]));
        ans += 0.25*(h1 + h2);
        h1 = h2;
    }

    printf("%.5lf\n", ans);
}