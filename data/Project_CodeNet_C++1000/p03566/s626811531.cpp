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


int main(){
    int n;
    cin >> n;
    vector<int> t(n),v(n);
    int sumT = 0;
    for(int i = 0; i < n; i++) cin >> t[i], sumT += t[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<ld> a(sumT*2+1, 1e9);
    int nowt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sumT*2+1; j++) {
            if(nowt*2 <= j && j <= (nowt+t[i])*2) {
                chmin(a[j], (ld)v[i]);
            } else if (j < nowt*2) {
                ld tt = (nowt*2-j)*0.5+v[i];
                chmin(a[j], tt);
            } else {
                ld tt = (j-(nowt+t[i])*2)*0.5+v[i];
                chmin(a[j], tt);
            }
        }
        nowt += t[i];
    }
    for(int i = 0; i < sumT*2+1; i++) {
        if(i <= sumT) {
            chmin(a[i], (ld)i*0.5);
        }else {
            chmin(a[i], sumT-(ld)i*0.5);
        }
    }
    ld ans = 0;
    for(int i = 0; i < sumT*2; i++) {
        ans += (a[i]+a[i+1])*0.25;
    }
    cout << fixed << setprecision(20) << ans << endl;
}