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
 
signed main(){
 
    int N;
    cin >> N;
    vector<int> t(N), v(N);
    readv(t);
    readv(v);

    vec T(N + 1, 0);
    REP(i, N) T[i + 1] = T[i] + t[i];
    
    vec maxv(2 * T[N] + 1, INF);
    REP(i, N){
        FOR(j, 0, 2 * T[i]) maxv[j] = min(maxv[j], 2 * v[i] + llabs(2 * T[i] - j));
        FOR(j, 2 * T[i], 2 * T[i + 1] + 1) maxv[j] = min(maxv[j], 2 * v[i]);
        FOR(j, 2 * T[i + 1] + 1, 2 * T[N] + 1) maxv[j] = min(maxv[j], 2 * v[i] + llabs(2 * T[i + 1] - j));
    }
    FOR(j, 0, 2 * T[N] + 1) maxv[j] = min(maxv[j], min(j, 2 * T[N] - j));

    double ans = 0;
    REP(i, 2 * T[N]) ans += (maxv[i] + maxv[i + 1]) * 0.125;
 
    cout << setprecision(10) << ans;
    
    return 0;
}