#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;



int main(){FIN

    ll n;cin>>n;
    double t,a;cin>>t>>a;
    double sa = 100000000000.0;
    ll num = 0;
    REP(i,n){
        double h;cin>>h;
        // cout<<sa<<endl;
        // cout<<abs(t-h*0.006-a)<<endl;
        if (sa > abs(t-h*0.006-a)){
            sa = abs(t-h*0.006-a);
            num = i+1;
        } 
    }
    cout<<num<<endl;
    return 0;
}