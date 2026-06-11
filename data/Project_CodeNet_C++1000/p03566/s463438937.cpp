//t秒間で初速V0, 最高速度Vm, 最終速度V1で走るときの最大の速度を求める
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double area(double v0, double v1, double vm, double t){
    //(0, v0)から傾き1の直線を引き、(t, v1)から傾き-1の直線を引き、その交点を(tp, vp)とする。
    double tp = (t + v1 - v0)/2.0; 
    double vp = (t + v1 + v0)/2.0;
    if(vp > vm) {
        return vm * t - (vm - v0)*(vm - v0)/2.0 - (vm - v1)*(vm - v1)/2.0;
    }
    else {
        return vp*t - tp*tp/2.0 - (t - tp)*(t - tp)/2.0;
    }
}

int main()
{
    int N;
    cin >> N;
    int t[N+1], v[N+1];
    for(int i = 1; i <= N; ++i) cin >> t[i];
    for(int i = 1; i <= N; ++i) cin >> v[i];
    t[0] = 0; v[0] = 0;

    int kv[N+1]; // kv[i] -- 区間iが終わるときの終速度
    kv[0] = 0, kv[N] = 0;
    for(int i = 1; i < N; ++i) {
        kv[i] = min(kv[i-1] + t[i], min(v[i], v[i+1]));
    }
    for(int i = N-1; i > 0; --i) {
        kv[i] = min(kv[i+1] + t[i+1], kv[i]);
    }

    /*
    for(int i = 0; i <= N; ++i) cout << kv[i] << " ";
    cout << endl;
    */
    double res = 0;
    for(int i = 1; i <= N; ++i) {
        res += area(kv[i-1], kv[i], v[i], t[i]);
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}