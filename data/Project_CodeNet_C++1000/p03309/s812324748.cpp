#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<"\n"


int main(){
    int n,t;
    cin >> n;
    int a[n];
    REP(i,n){
        cin >> t;
        a[i]=t-i-1;
    }
    sort(a,a+n);
    ll mid = a[n/2];
    ll ans =0;
    REP(i,n)ans+=abs(a[i]-mid);
    COUT(ans);
    return 0;
}