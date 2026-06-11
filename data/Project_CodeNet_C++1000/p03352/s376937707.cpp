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

    ll x;cin>>x;
    vll a(1001,0);
    a[1]=1;
    FOR(i,2,1000){
        ll now = 2;
        while(pow(i,now)<=1000){
            a[pow(i,now)] = 1;
            now++;
        }


    }
    FORR(i,x,1){
        if(a[i]>0) {cout<<i<<endl; return 0;}
    }
    return 0;
}