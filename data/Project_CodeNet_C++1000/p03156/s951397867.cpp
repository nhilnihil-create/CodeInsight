#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n;
    int a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    vector<int> cnt(3,0);
    rep(i,n){
        if(p[i]<=a) ++cnt[0];
        else if(p[i]<=b) ++cnt[1];
        else ++cnt[2];
    }
    int ans = min({cnt[0],cnt[1],cnt[2]});
    cout << ans << endl;
    return 0;
}