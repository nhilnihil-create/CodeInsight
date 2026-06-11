#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int cnt = 0;
    for(int i = 0;i <= (n+r-1)/r; i++){
        for(int j = 0; j <= (n - i*r + g - 1)/g; j++){
            if( (n - i*r - j*g)%b == 0 && (n - i*r - j*g) >= 0) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}