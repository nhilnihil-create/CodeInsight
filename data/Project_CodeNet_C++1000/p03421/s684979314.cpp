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

vec slide(vec v, int n){
    int N = v.size();
    vec w(N);
    REP(i, n) w[N - 1 - i] = v[i];
    REP(i, N - n) w[i] = v[n + i];
    return w;
}

signed main(){

    int N, A, B; cin >> N >> A >> B;

    if(A + B > N + 1 || A * B < N){
        cout << -1 << endl;
        return 0;
    }

    int n = (N - 1) / B + 1;
    mat ans(n);
    int v = 1;
    REP(i, n){
        int m = min(N, B);
        ans[i] = vec(m);
        IREP(j, m){
            ans[i][j] = v;
            v++;
        }
        N -= m;
    }

    int a = n;
    IREP(i, n){
        int k = min((int)ans[i].size() - 1, A - a);
        //cout << i << " " << k << endl;
        ans[i] = slide(ans[i], k);
        a += k; 
    }

    REP(i, n) REP(j, ans[i].size()) cout << ans[i][j] << " ";

    
    return 0;
}