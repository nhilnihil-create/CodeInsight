#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    double ans=0;
    cin>>n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i,n) cin>>x[i]>>u[i];
    rep(i,n) {
        if (u[i]=="JPY") ans+=x[i];
        else ans+=380000.0*x[i];
    }
    printf("%.6f\n",ans);
}
