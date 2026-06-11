#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int64_t i = 0; i < n; i++)
#define REPR(i, n) for(int64_t i = n; i >= 0; i--)
#define FOR(i, m, n) for(int64_t i = m; i < n; i++)
#define FORR(i, m, n) for(int64_t i = m; i >= n; i--)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}
template<class T>
inline bool chmax(T &a, T b) {if(a < b) {a = b;return true;}return false;}
template<class T>
inline bool chmin(T &a, T b) {if(a > b) {a = b;return true;}return false;}
const ll INF= 1ll << 60;
const ll MOD = 1000000007;
double EPS = 1e-10;
//----------------------------------------------------------

char C;
bool n[10];

int main(){
    int N[4];
    cin >> N[0] >> N[1] >> N[2] >> N[3];
    REP(i,4)
    {
        n[N[i]]=true;
    }
    if(n[1] && n[9] && n[7] && n[4])cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}