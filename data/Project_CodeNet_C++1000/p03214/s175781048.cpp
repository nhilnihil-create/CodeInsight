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
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int res = 0;
    rep(i,n) res += a[i];

    int mn = INF;
    int idx = -1;
    rep(i,n){
        if(abs(n*a[i]-res)<mn){
            mn = abs(n*a[i]-res);
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}