#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)


int main()
{
    int N;
    cin >> N;
    double T[N], V[N];
    rep(i, N) cin >> T[i];
    rep(i, N) cin >> V[i];

    //各iの終りでの可能な最大速度を計算する
    double endSpeed[N];
    endSpeed[N - 1] = 0; //終点は速度0必須
    for (int i = N - 2; i >= 0; i--) {
        double dt = T[i + 1];
        double v1 = endSpeed[i + 1] + dt;
        endSpeed[i] = min(V[i + 1], min(v1, V[i]));
    }
    //先頭から計算
    double spd = 0;
    double area = 0;
    for (int i = 0; i < N; i++) {
        //仮に区間最高速がないとしたときの、加速と減速グラフの交点を計算
        double dt = T[i];
        double ed = min(endSpeed[i], min(V[i], spd + T[i]));
        double dv = (ed - spd);
        double ta = (dv + dt) / 2.0;
        double va = ta + spd;
        if (va > V[i]) {
            //最高速に達する場合。加速完了地点と減速完了地点を計算
            double t1 = V[i] - spd;
            double t2 = T[i] - (V[i] - ed);
            area += (spd + V[i]) * (t1) / 2.0;
            area += V[i] * (t2 - t1);
            area += (V[i] + ed) * (T[i] - t2) / 2.0;
        } else {
            //
            area += (spd + va) * ta / 2.0;
            area += (va + ed) * (T[i] - ta) / 2.0;
        }
        spd = ed;
    }
    printf("%.5f\n", area);
    return 0;
}
