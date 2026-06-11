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

int main(){
    int N, M;
    cin >> N >> M;
    ll A[2][N], B[2][N], C[2][N];
    rep(i, N) {
        ll a, b, c;
        cin >> A[0][i] >> B[0][i] >> C[0][i];
        A[1][i] = -A[0][i];
        B[1][i] = -B[0][i];
        C[1][i] = -C[0][i];
    }

    ll Z[N];
    ll ans = 0;
    rep(i, 2) {
        rep(j, 2) {
            rep(k, 2) {
               rep(l, N) {
                   Z[l] = A[i][l] + B[j][l] + C[k][l];
               }
               sort(Z, Z+N);
               reverse(Z, Z+N);
               ll tmp = 0;
               rep(i, M) {
                    tmp += Z[i];
               }
               chmax(ans, tmp);
            }
        }

    }
    cout << ans << endl;

}