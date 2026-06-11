#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// sを2倍の大きさにして考える。大きさ2n*2n
// a a      a a a a
// a a 　→  a a a a
//          a a a a
//          a a a a
// A=0、B=0からn*nの盤面を抜き出し、その盤面が対称であれば、A=1, B=1, A=2, B=2の場合にも対称が成り立つ。
// したがって、A=0, B=i (i = 0,...,n-1)の盤面についてそれぞれ対称かどうか確認し、
// 対称であればA=1, B=i+1...の時にも対称であるため、よい盤面の選び方をn個増加させるということを繰り返す。

int main(){
    Init();
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
        s[i] += s[i];
    }

    // A=0, b=iからn*nの盤面を切り出して、その盤面が対称であれ選び方をn個増加させる。
    ll ans = 0;
    for(ll i=0; i<n; i++){
        bool symmetry = true;
        for(ll y=0; y<n; y++){
            if(!symmetry) break;
            for(ll x=y+1; x<n; x++){
                if(s[y][x+i] != s[x][y+i]) symmetry = false;
                if(!symmetry) break;
            }
        }
        if(symmetry) ans += n;
    }
    cout << ans << endl;
}