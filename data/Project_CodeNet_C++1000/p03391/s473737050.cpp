#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define srep(i,l,n) for(int i = l; i < (int)(n); i++)
#define drep(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void err() {cout << -1 << endl;}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back

const int MOD = 1000000007;
const int INF = 1e9;

#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll sum = 0;
    bool ok = false;
    rep(i, n) {
        cin >> a[i] >> b[i];
        if(a[i] != b[i]) ok = true;
        sum += a[i];
    }
    if(!ok) {
        cout << 0 << endl;
        return 0;
    }
    int mi = INF;
    rep(i, n) {
        if(a[i] > b[i]) chmin(mi, b[i]);
    }
    ll ans = sum - mi;
    cout << ans << endl;
}