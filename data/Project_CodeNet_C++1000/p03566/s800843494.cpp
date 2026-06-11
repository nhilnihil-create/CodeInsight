#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }



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
    vector<int> t(N), v(N);
    readv(t);
    readv(v);
 
    vec v_max(N + 1);
    v_max[0] = 0;
    FOR(i, 1, N){
        v_max[i] = min(v[i - 1], v[i]);
    }
    v_max[N] = 0;

    priority_queue<Pii> que;
    REP(i, N + 1) que.push(Pii(-1 * v_max[i], i));

    while(!que.empty()){
        Pii p = que.top(); que.pop();
        int v0 = -1 * p.first;
        int i0 = p.second;
        if(v0 > v_max[i0]) continue;
        if(i0 != 0){
            if(v_max[i0] + t[i0 - 1] < v_max[i0 - 1]){
                v_max[i0 - 1] = v_max[i0] + t[i0 - 1];
                que.push(Pii(-1 * v_max[i0 - 1], i0 - 1));
            }
        }
        if(i0 != N){
            if(v_max[i0] + t[i0] < v_max[i0 + 1]){
                v_max[i0 + 1] = v_max[i0] + t[i0];
                que.push(Pii(-1 * v_max[i0 + 1], i0 + 1));
            }
        }
    }
 
    double ans = 0.0;
    REP(i, N) ans += calcdist((double)v_max[i], (double)v_max[i + 1], (double)v[i], t[i]);
 
    cout << setprecision(10) << ans;
    
    return 0;
}