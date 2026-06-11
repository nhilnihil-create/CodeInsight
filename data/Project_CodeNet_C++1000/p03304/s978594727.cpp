#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//input


int main(){
    double n,m,d;
    cin >> n >> m >> d;
    double ans = (m-1);
    if(d!=0)ans *= 2;
    ans /= n;
    ans /= n;
    ans *= n-d;
    printf("%.10lf",ans);
    return 0;
}

