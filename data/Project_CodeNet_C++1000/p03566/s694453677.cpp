#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int N;
vector<int> t(105, 0);
vector<int> v(105, 0);
vector<double> cum(105, 0);

double f(double time, int id){
    if(id == 0) {
        if (time == 0) return 0;
        else return time;
    } else if (id == N+1) {
        if(time == cum[N]) return 0;
        else return cum[N]-time;
    }

    if (cum[id-1]<=time && time<=cum[id]) return v[id];
    else if(time <= cum[id-1]) return v[id]+cum[id-1]-time;
    else return v[id]+time-cum[id];
}

int main(void){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> t[i];
    for(int i=1; i<=N; i++) cin >> v[i];
    for(int i=1; i<=N; i++) cum[i] = cum[i-1]+t[i];

    double ans = 0.0;
    double prev = 0.0;
    for(double t=0.5; t<=cum[N]; t+=0.5){
        double now = 10000.0;
        for(int id=0; id<=N+1; id++) now = min(now, f(t, id));
        ans += (prev+now)*0.25;
        prev = now;
    }
    //cout << cum[N] << endl;

    printf("%.8lf\n", ans);

}