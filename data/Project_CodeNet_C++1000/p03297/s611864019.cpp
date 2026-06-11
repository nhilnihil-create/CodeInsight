#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "agc026_b"
ll a, b, c, d;
void solve(){
    read(a);
    read(b);
    read(c);
    read(d);
    if(a<b) puts("No");
    else{
        ///a>=b;
        if(d<b) puts("No");
        else{
            ///a%b>c
            d%=b;
            a%=b;
            ///a+d, a+2d, a+3d, ...
            d=__gcd(d, b);
            if(d==0){
                if(a>c) puts("No");
                else puts("Yes");
            }
            else{
                a%=d;
                ///a+x*d>c
                ll x=(c-a)/d;
                while(a+x*d<=c) x++;
                if(a+x*d>=b) puts("Yes");
                else puts("No");
            }
        }
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    while(t--) solve();
}