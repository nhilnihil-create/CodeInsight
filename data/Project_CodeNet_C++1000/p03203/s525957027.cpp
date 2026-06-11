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

    int H, W, N; cin >> H >> W >> N;
    vec X(N), Y(N);
    mat O(H, vec(0));
    REP(i, N){
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
        O[X[i]].push_back(Y[i]);
    }
    REP(i, H) SORT(O[i]);

    int ans = 0, M = 0;
    FOR(i, 1, H){
        if(O[i].size() > 0){
            if(O[i][0] <= M) break;
            int j = Lower_bound(O[i], M + 1);
            if(!(j != O[i].size() && O[i][j] == M + 1)) M++;
        }else M++;
        ans++;
    }
    ans++;

    cout << ans;


    
    return 0;
}