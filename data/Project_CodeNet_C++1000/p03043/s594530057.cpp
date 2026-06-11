#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


signed main(){
    int n, k;
    cin >> n >> k;
    long double ans = 0;
    for(int i = 1; i <= n; i++){
        int tmp = i;
        int num = 0;
        long double div_n = 1.0/n;
        while(tmp < k){
            tmp *= 2;
            div_n /= 2;
        }
        ans += div_n;
    }

    printf("%.12Lf\n", ans);

}