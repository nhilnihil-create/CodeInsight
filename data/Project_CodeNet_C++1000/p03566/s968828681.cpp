#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int N;
vector<int> cum(110, 0), v(110, 0);

double f(int i, double t){
    if(i == 0) return t;
    if(i == N+1) return cum[N]-t;

    if(t <= cum[i-1]) return v[i]+cum[i-1]-t;
    else if(t <= cum[i]) return v[i];
    else return v[i]+t-cum[i];
}   

int main(){
    cin >> N;
    vector<int> t(N+2);
    for(int i=1; i<=N; i++) cin >> t[i];
    for(int i=1; i<=N; i++) cin >> v[i];

    for(int i=1; i<=N; i++) cum[i] = cum[i-1]+t[i];

    double ans = 0.0;
    double h1 = 0, h2;
    for(double x=0.5; x<=cum[N]; x+=0.5){
        double h2 = 10000000;
        for(int i=0; i<=N+1; i++) h2 = min(h2, f(i, x));
        ans += (h1 + h2) * 0.5 / 2;
        h1 = h2;
    }

    printf("%.8lf\n", ans);
    return 0;
}