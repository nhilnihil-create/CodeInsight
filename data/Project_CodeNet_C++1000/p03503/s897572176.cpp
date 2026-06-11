#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int mod = 1000000007;


int count(vvi x, vvi f){
    int cnt = 0;
    rep(i, 5)rep(j, 2){
        if(x[i][j] && f[i][j]) cnt++;
    }
    return cnt;
}

int main(){
    //入力部
    int n;
    cin >> n;
    vector<vvi> F(n, vvi(5, vi(2)));
    rep(i, n){
        rep(j, 5){
            cin >> F[i][j][0] >> F[i][j][1];
        }
    }
    vvi P(n, vi(11));
    rep(i, n){
        rep(j, 11){
            cin >> P[i][j];
        }
    }

    vvi confirm(5, vi(2));

    //処理部
    int ans = -INF;
    rrep(i, (1<<10) - 1){
        vvi x(5, vi(2));
        int tmp_i = i;
        rep(xi, 5){
            x[xi][0] = (tmp_i&1);
            x[xi][1] = ((tmp_i>>1)&1);
            tmp_i = tmp_i>>2;
        }
        
        int bene = 0;
        
        //printf("%d:\n", i);
        rep(j, n){
            bene += P[j][count(x, F[j])];
            //printf("%d ", P[j][count(x, F[j])]);
        }
        //printf("\n\n");

        if(ans < bene){
            confirm = x;
            ans = bene;
            //printf("%d %d\n", i, bene);
        }
    }

    /*
    rep(i, n){rep(j, 5){
        rep(k, 2){
            printf("%d, ", F[i][j][k]);
        }
        printf("\n");
    }printf("\n");}
    
    
    rep(i, 5){rep(j, 2){
        printf("%d, ", confirm[i][j]);
    }printf("\n");}
    */


    //出力部
    cout << ans << endl;

    return 0;
}