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

ld dp[310][310][310] = {(ld)0};
int n;

ld rec(int i, int j, int k) {
    if(dp[i][j][k] != (ld)0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return (ld)0.0;

    ld res = 0;
    if(i > 0)res += i * rec(i-1, j, k);
    if(j > 0)res += j * rec(i+1, j-1, k);
    if(k > 0)res += k * rec(i, j+1, k-1);
    res += n;
    res *= (ld)1.0 / (i + j + k);

    return dp[i][j][k] = res;
}

int main(){
    cin >> n;
    int one = 0, two = 0, three = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1) one++;
        else if(a == 2) two++;
        else three++;
    }
    ld ans = rec(one, two, three);
    cout << fixed << setprecision(20) << ans << endl;
}