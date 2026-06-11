#include <bits/stdc++.h>
using intl = long long;
using itnl = long long;//typo用
using uintl = unsigned long long;
using itn = int;//typo用
using ld = long double;
using namespace std;
#define rep(i, n) for(intl i = 0; i < (intl)(n); i++)
#define rrep(i, n) for(intl i = (intl)(n) - 1; i >= 0; i--)
#define repi(i, a, b) for(intl i = (intl)(a); i < (intl)(b); i++)
#define rrepi(i, a, b) for(intl i = (intl)(a) - 1; i >= (intl)(b); i--)
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
#define pii pair<intl,intl>
const intl INF = 1e9;
const intl MOD = 1e9+7;
const ld EPS = 1.0e-14;//-9
const ld PI = acos(-1);
void fp(bool f){cout << (f ? "Yes" : "No") << endl;}
void fp(bool f, string s, string t){cout << (f ? s : t) << endl;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true;} return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true;} return false; }
intl gcd(intl a, intl b){ if(!b)return a; return gcd(b, a % b); }
intl lcm(intl a,intl b){ return a / gcd(a, b) * b; }
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


signed main(){
    cout << fixed << setprecision(10);
    intl h,w;
    cin >> h >> w;
    intl a[h + 2][w + 2];
    rep(i,h + 2){
        rep(j, w + 2){
            if((i == 0)||(i == h + 1)||(j == 0)||(j == w + 1))a[i][j] = 0;
            else cin >> a[i][j];
        }
    }
    intl cnt = 0;
    vector<tuple<intl,intl,intl,intl> > t;
    repi(i,1,h + 1){
        repi(j,1,w + 1){
            if(a[i][j] % 2){
                if(a[i + 1][j] % 2){
                    a[i + 1][j]++;
                    t.pb(make_tuple(i,j,i + 1,j));
                    cnt++;
                }
                else if(a[i][j + 1] % 2){
                    a[i][j + 1]++;
                    t.pb(make_tuple(i,j,i,j + 1));
                    cnt++;
                }
                else{
                    if(i < h){
                        a[i + 1][j]++;
                        t.pb(make_tuple(i,j,i + 1,j));
                        cnt++;
                    }
                    else if(j < w){
                        a[i][j + 1]++;
                        t.pb(make_tuple(i,j,i,j + 1));
                        cnt++;   
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    for(auto i : t){
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << " " << get<3>(i) << endl;
    }
    return 0;
}
