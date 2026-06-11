#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    double n,m,d;
    cin>>n>>m>>d;
    double x;
    if(d==0) x=n;
    else x=2*(n-d);
    double ans=(x/(n*n))*(m-1);

    cout<<fixed<<setprecision(10)<<ans<<endl;

}