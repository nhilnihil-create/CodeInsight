#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

#define t_max 100000+5

int v[30][t_max] = {};

int main(){
    int i, j;
    int n, c;
    cin >> n >> c;
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        c--;
        v[c][a]++;
        v[c][b]--;
    }
    rep(i, c) rep(j, t_max-1) v[i][j+1] += v[i][j];
    rep(i, c) rep(j, t_max-1) {
        if (v[i][j] == 0 && v[i][j + 1] == 1) v[i][j]++;
    }
    int ans = 0;
    rep(j, t_max) {
        int cnt = 0;
        rep(i, c) if (v[i][j]) cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << endl;

}