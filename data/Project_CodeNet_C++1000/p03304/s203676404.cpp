#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;

int main() {
    ld n,m,d;
    cin >> n >> m >> d;
    ld u=(n-d)*2,mm=m-1;
    if(d==0) u=n-d;
    ld ans=mm/n*u/n;
    cout << fixed << setprecision(10) << ans << endl;    
}
