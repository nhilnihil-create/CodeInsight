#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define int long long
using namespace std;

typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

double calcdist(double vi, double vf, double vm, double T){
    double dist;
    double vm2 = (T + vi + vf) / 2.0;
    if(vm2 > vm){
        dist = (vm + vi) * (vm - vi) / 2.0 + (vm + vf) * (vm - vf) / 2.0 + vm * (T - 2.0 * vm + vi + vf);
    }else{
        dist = (vm2 + vi) * (vm2 - vi) / 2.0 + (vm2 + vf) * (vm2 - vf) / 2.0;
    }
    return dist;
}

signed main(){

    int N;
    cin >> N;
    vector<int> t(N), v(N), T(N + 1);
    readvec(t);
    readvec(v);

    vector<Pii> v_max(N + 1);
    v_max[0] = Pii(0, 0);
    FOR(i, 1, N){
        v_max[i] = Pii(min(v[i - 1], v[i]), i);
    }
    v_max[N] = Pii(0, N);
    SORT(v_max);

    T[0] = 0;
    REP(i, N){
        T[i + 1] = T[i] + t[i];
    }

    #define INF 1000000000000000
    vector<int> v_max_f(N + 1, INF);
    REP(i, N + 1){
        int vtmp = v_max[i].first;
        int itmp = v_max[i].second;

        REP(j, N + 1){
            v_max_f[j] = min(v_max_f[j], vtmp + llabs(T[j] - T[itmp]));
        }
    }

    double ans = 0.0;
    REP(i, N){
        ans += calcdist((double)v_max_f[i], (double)v_max_f[i + 1], (double)v[i], (double)t[i]);
    }

    cout << setprecision(10) << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}
