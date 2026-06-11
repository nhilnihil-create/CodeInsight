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

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl; }}



signed main(){

    int N, K, Q; cin >> N >> K >> Q;
    vec A(N); readv(A);
    int ans = INF;

    REP(i, N){
        int m = A[i];
        vec v(0), w(0);
        REP(j, N + 1){
            if(j == N || A[j] < m){
                if(v.size() >= K){
                    SORT(v);
                    REP(k, v.size() - K + 1) w.push_back(v[k]);
                }
                v = vec(0);
            }else v.push_back(A[j]);
        }
        if(w.size() >= Q){
            SORT(w);
            ans = min(ans, w[Q - 1] - m);
        }
    }
    cout << ans << endl;
    
    return 0;
}