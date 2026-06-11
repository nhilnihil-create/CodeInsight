#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    ll d,g;
    cin >> d >> g;
    ll p[d],c[d];
    for(i=0;i<d;i++){
        cin >> p[i] >> c[i];
    }
    ll ret = INF;
    for(i=0;i<1<<d;i++){
        ll top=INF,prob_cnt=0,point=0;
        for(j=d-1;j>=0;j--){
            if(i>>j & 1){
                prob_cnt += p[j];
                point += p[j]*(j+1)*100 + c[j];
            }else {
                if(top == INF)top = j;
            }
        }
        if(point >= g){
            ret = min(ret,prob_cnt);
        }else {
            point = g-point; // 残りの得点
            if(point<=(p[top]-1)*100*(top+1)){
                prob_cnt += (point-1+((top + 1) * 100)) / ((top + 1) * 100);
                ret = min(ret,prob_cnt);
            }
        }
    }
    cout << ret << endl;
    return 0;
}