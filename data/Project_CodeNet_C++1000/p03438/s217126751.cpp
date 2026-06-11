#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N;cin >> N;
    vector<LL> a(N);
    vector<LL> b(N);
    rep(i,N)cin >> a[i];
    rep(i,N)cin >> b[i];


    LL sa = 0;
    LL suma = 0;
    LL sumb = 0;

    rep(i,N){
        if(a[i] < b[i])sa += (b[i] - a[i] + 2 -1)/2;
        suma += a[i];
        sumb += b[i];
    }

    LL tmp = sumb - suma;



    if(tmp >= sa)cout << "Yes" << endl;
    else cout << "No" << endl;
}