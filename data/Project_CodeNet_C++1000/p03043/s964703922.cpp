#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

ll dp[100100];
int jij(int x,int y){
    int ans = 0;
    while(y<x){
        y*=2;
        ans++;
    }
    return ans;
}
int main() {
    int n,k;
    cin >> n >> k;
    double p=0.0;
    for(int i = 1;i<=n;++i){
          double d =1.0;
          rep(j,jij(k,i)) d/=2;
          p+=d;
    }
    cout << fixed <<setprecision(10) << p/n  <<endl;
}