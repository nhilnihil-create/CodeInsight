//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    cout<<fixed<<setprecision(15);
    ll n,m,d; cin>>n>>m>>d;
    ld ans=(ld)(n-d)*(m-1)/(n*n);
    if(d>0) ans*=2;
    cout<<ans<<endl;
}
