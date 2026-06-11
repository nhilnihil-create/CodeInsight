#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

// Pは順列
// |P| = N
// LIS(P) = A
// LDS(P) = B
// Pを求めよ(ないかも)
// 1<=N,A,B<=3*10^5
// LISとLDSで重複している要素はたかだか1つなので
// A + B <= N + 1
// Nが大きすぎると駄目で
// 最大のケースで例えばA=2, B=3とすると
// N = A*B=6で
// 3, 2, 1, 6, 5, 4
// のように構成できる
// N <= A * B
// A + B - 1 <= N <= A*B
// 構成の仕方
// とりあえず先頭にB個の要素で{B, B-1, ,,,.,1}
// あとは大きさB以下で後ろに同様の単調減少列をくっつけていく

const int N_MAX = 3e5;
int N, A, B;
int ans[N_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    cin >> N >> A >> B;
    rep(i, N)ans[i] = i + 1;
    if (A + B - 1 <= N && N <= (ll)A*B) {
        reverse(ans, ans + B);
        for (int i = 1, k = B; i < A; ++i) {
            // n個の元をm個に分割
            // 分割の大きさCは
            // 1<=C<=min(n-(m-1), B)
            int n = N - k, m = A - i;
            int C = min(n - m + 1, B);
            reverse(ans + k, ans + k + C);
            k += C;
        }
        rep(i, N)cout << ans[i] << (i != N - 1 ? ' ' : '\n');
    } else {
        cout << -1 << endl;
    }
}