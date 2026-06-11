#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    int n,k;
    cin >> n >> k;
    double ans=0;
    vector<ll> p(25);
    p[0]=1;
    rep(i,24) p[i+1]=p[i]*2;
    rep(i,n) {
        int j=i+1;
        int cnt=0;
        while (j<k) {
            j*=2;
            ++cnt;
        }
        ans+=1.0/(n*p[cnt]);
    } 
    
    cout << fixed << setprecision(15) << ans << endl;
   
    return 0;   
}