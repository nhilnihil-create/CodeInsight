#include <bits/stdc++.h>
using intl = long long;
using itnl = long long;
using itn = int;
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
#define cin(i, a) rep(i, alength(a))cin >> a[i]
#define ccin(i, j, a) rep(i, alength(a))rep(j, alength(a[i]))cin >> a[i][j]
#define debug(x) cout << #x << ":" << x << endl
#define rdebug(i,x) rep(i, alength(x))cout << #x << "[" << i << "]:" << x[i] << endl
#define rrdebug(i, j, x) rep(i, alength(x))rep(j, alength(x[i]))cout << #x << "[" << i << "][" << j << "]:" << x[i][j] << endl
#define sqrt sqrtl
#define itn int
#define double ld
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
intl kai(intl k){
    intl a = 1;
    for(int i = 2; i <= k; i++){
        a *= i;
    }
    return a;
}
intl gcd(intl a, intl b){ if(!b)return a; return gcd(b, a % b); }
intl lcm(intl a,intl b){ return a / gcd(a, b) * b; }
intl digit10(intl a){
    intl b = 0;
    do{
        a /= 10;
        b++;
    }while(a);
    return b;
}
//-------------------------------------------------------------------------------

intl n;
intl v[100000];

void input_var(){
    cin >> n;
    rep(i,n)cin >> v[i];
}
//-------------------------------------------------------------------------------

signed main(){
    cout << fixed << setprecision(10);
    input_var();
    intl a[n/2],b[n/2];
    for(intl i = 0; i < n; i += 2)a[i/2] = v[i];
    for(intl i = 1; i < n; i += 2)b[i/2] = v[i];
    map<intl,intl> m1,m2;
    rep(i,n/2){
        if(m1.find(a[i]) != m1.end())m1[a[i]]++;
        else m1[a[i]] = 1;
        if(m2.find(b[i]) != m2.end())m2[b[i]]++;
        else m2[b[i]] = 1;
    }
    intl ma1,ma2,mb1,mb2,idx1,idx2;
    ma1 = 0;
    ma2 = 0;
    mb1 = 0;
    mb2 = 0;
    for(auto i: m1){
        if(i.second > ma1){
            idx1 = i.first;
            ma2 = ma1;
            ma1 = i.second;
        }
        else if(i.second > ma2){
            ma2 = i.second;
        }
        // /cout << i.first << ":" << i.second << endl;
    }
    //cout << endl;
    for(auto i: m2){
        if(i.second > mb1){
            idx2 = i.first;
            mb2 = mb1;
            mb1 = i.second;
        }
        else if(i.second > mb2){
            mb2 = i.second;
        }
        //cout << i.first << ":" << i.second << endl;
    }
    intl num = ma1 + mb1;
    if(idx1 == idx2){
        num = max(ma2 + mb1, ma1 + mb2);
    }
    cout << n - num << endl;
    return 0;
}