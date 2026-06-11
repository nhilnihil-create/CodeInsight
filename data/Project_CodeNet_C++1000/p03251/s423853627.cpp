#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)
#define IN(a, x, b) (a<=x && x<b)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main()
{
    INIT;
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> s(n);
    vector<int> t(m);
    int max_x = -101;
    REP(j,n){
        cin >> s.at(j);
        max_x = max(max_x, s.at(j));
    }
    int min_y = 10000;
    REP(k, m){
        cin >> t.at(k);
        min_y = min(min_y, t.at(k));
    }
    int ans_1 = false;
    int ans_2 = false;
    int ans_3 = false;
    int ans = false;
    for(int i = x + 1; i <= y; i++){
        ans_1 = false;
        ans_2 = false;
        ans_3 = false;
        if(max_x < i) ans_1 = true;
        if(min_y >= i) ans_2 = true;   
        if(x < i && i <= y) ans_3 = true;
        if(ans_1 && ans_2 && ans_3) ans = true;
    }
    cout << (ans ? "No War" : "War") << endl;
    return 0;
}
