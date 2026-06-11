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
    if(0.0 <= x && x <= l) return v+l-x;
    else if(l <= x && x <= r) return v;
    else return v+(x-r);
}

int main(){
    int N; cin >> N;
    vector<int> l(N+2), r(N+2), v(N+2), t(N+1);
    for(int i=1; i<=N; i++) cin >> t[i];
    for(int i=1; i<=N; i++) cin >> v[i];
    
    l[1] = 0, r[1] = t[1];
    for(int i=2; i<=N; i++){
        l[i] = r[i-1];
        r[i] = l[i]+t[i];
    }

    l[0] = 0, r[0] = 0, v[0] = 0;
    l[N+1] = r[N], r[N+1] = r[N]; v[N+1] = 0;

    double ans = 0.0;

    double h1 = 0.0;
    for(double a=0.5; a<=r[N]; a+=0.5){
        double h2 = 500;
        for(int i=0; i<N+2; i++) h2 = min(h2, f(a, l[i], r[i], v[i]));
        ans += (h1 + h2)*0.25;
        h1 = h2;
    }

    printf("%.6f\n", ans);
}