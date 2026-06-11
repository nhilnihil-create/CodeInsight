#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end()
#define out(ppp) cout<<(ppp)<<endl
#define out1(ppp) cout<<(ppp) 
#define MAX_CHAR 256

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;

void solve(){
    int a,b,t;
    cin>>a>>b>>t;
    int ans=t/a;
    out(ans*b);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}