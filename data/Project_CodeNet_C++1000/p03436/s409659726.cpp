#include <bits/stdc++.h>
using intl = long long;
using itnl = long long;//typo用
using itn = int;//typo用
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define rrep(i, n) for(intl i = (intl)(n) - 1; i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define rrepi(i, a, b) for(intl i = (intl)(a); i > (intl)(b); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define alength(a) (sizeof(a) / sizeof(a[0]))
#define debug(x) cout << #x << ":" << x << endl
#define rdebug(i,x) rep(i, alength(x))cout << #x << "[" << i << "]:" << x[i] << endl//1次元配列の出力
#define rrdebug(i, j, x) rep(i, alength(x))rep(j, alength(x[i]))cout << #x << "[" << i << "][" << j << "]:" << x[i][j] << endl//二次元配列の出力
#define pb push_back
#define mp make_pair
#define Pii pair<intl,intl>
const intl INF = 1e9;
const intl MOD = 1e9+7;
const ld EPS = 1.0e-14;//-9
const ld PI = acos(-1);
void fp(bool f){cout << (f ? "Yes" : "No") << endl;}
void fp(bool f, string s, string t){cout << (f ? s : t) << endl;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }
intl kai(intl k){//k!を求める関数,
    intl a = 1;
    for(int i = 2; i <= k; i++){
        a *= i;
    }
    return a;
}
intl digit10(intl a){//aを10進数で表したときの桁数を求める関数
    intl b = 0;
    do{
        a /= 10;
        b++;
    }while(a);
    return b;
}

//--------------入力受け取る場所----------------------------------------------------
int h,w;
char s[50][50];

void input_var(){
    cin >> h >> w;
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
        }
    }
}
//-------------------------------------------------------------------------------


signed main(){
    cout << fixed << setprecision(10);
    input_var();
    int cnt = 1;
    queue<pair<int,int> > q;
    bool flag[h][w];
    int board[h][w];
    m0(board);
    m0(flag);
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                board[i][j] = -1;
            }
            else board[i][j] = INF;
        }
    }

    q.push(mp(0,0));
    bool f = false;
    while(!q.empty()){
        int len = q.size();
        rep(i,len){
            pair<int,int> p = q.front();
            q.pop();
            if(flag[p.first][p.second])continue;
            flag[p.first][p.second] = true;
            if(p.first - 1 >= 0){
                if(s[p.first - 1][p.second] == '.'){
                    q.push(mp(p.first - 1, p.second));
                    board[p.first][p.second] = min(cnt,board[p.first][p.second]);
                }
            }
            if(p.second - 1 >= 0){
                if(s[p.first][p.second - 1] == '.'){
                    q.push(mp(p.first, p.second - 1));
                    board[p.first][p.second] = min(cnt,board[p.first][p.second]);
                }
            }
            if(s[p.first][p.second + 1] == '.'){
                q.push(mp(p.first, p.second + 1));
                board[p.first][p.second] = min(cnt,board[p.first][p.second]);
            }
            if(s[p.first + 1][p.second] == '.'){
                q.push(mp(p.first + 1, p.second));
                board[p.first][p.second] = min(cnt,board[p.first][p.second]);
            }
            if((p.first == h-1)&&(p.second == w-1)){
                f = true;
                board[p.first][p.second] = min(cnt,board[p.first][p.second]);
                break;
            }
        }
        cnt++;
        if(f)break;
    }/*
    rep(i,h){
        rep(j,w){
            if(board[i][j]== INF)board[i][j] = -1;
            printf("%3d",board[i][j]);
        }
        cout << endl;
    }*/
    if(f){
        int ans = 0;
        rep(i,h)rep(j,w)ans += (s[i][j] == '#');
        ans = h * w - ans - board[h-1][w-1];
        cout << ans << endl;
    }
    else cout << -1 << endl;
    return 0;
}
/*
50 50
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
.................................................
*/