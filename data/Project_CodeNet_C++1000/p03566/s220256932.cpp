#include <bits/stdc++.h>
using namespace std;

int N;
double t[102], T[102] = {0};
double V[102];

double velocity(double l, double r, double x, double v){
    if (0 <= x && x <= l) return v+l-x;
    else if(l <= x && x <= r) return v;
    else return v+x-r;
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> t[i];
        T[i+1] = T[i] + t[i];
    }
    for(int i=1;i<=N;i++) cin >> V[i];

    V[0] = 0;
    V[N+1] = 0;
    double time = 0;
    vector<double> F;
    while (time <= T[N+1]){
        double nowv = 1e9;
        for(int i=0;i<=N+1;i++){
            if (i==0) nowv = min(nowv, velocity(0, 0, time, 0));
            else if (i==N+1) nowv = min(nowv, velocity(T[N+1], T[N+1], time, 0));
            else nowv = min(nowv, velocity(T[i], T[i+1], time, V[i]));
        }
        F.push_back(nowv);
        time += 0.5;
    }
    double ans = 0;
    for(int i=0;i<F.size();i++){
        ans += 0.25*(F[i]+F[i+1]);
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}