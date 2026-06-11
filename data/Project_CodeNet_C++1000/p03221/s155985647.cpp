#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

struct tt {
    int a, b, c;
    bool operator<(const tt &x) const {
        if(a == x.a) return b < x.b;
        else return a < x.a;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<tt> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].c = i;
    }
    sort(a.begin(), a.end());
    vector<P> ans(m);
    int now = 1, cnt = 0;
    for(int i = 0; i < m; i++) {
        if(a[i].a == now) cnt++;
        else while(now != a[i].a) now++, cnt = 1;
        ans[a[i].c] = P(a[i].a, cnt);
    }
    for(int i = 0; i < m; i++) {
        cout << setw(6) << setfill('0') << ans[i].first << setw(6) << setfill('0') << ans[i].second << endl;
    }
}