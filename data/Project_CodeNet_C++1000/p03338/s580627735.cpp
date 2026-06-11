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
    string s;cin>>s;
    ll cnt=0; ll ans=0;
    FOR(i,0,n-2){
        for(char c='a';c<='z';c++){
            bool b1=false;
            bool b2=false;
            FOR(j,0,i) {if (s[j]==c) b1=true;}
            FOR(j,i+1,n-1) {if(s[j]==c) b2=true;}
            if(b1 && b2) cnt++;
        }
        // cout<<i<<' '<<cnt<<endl;
        ans = max(ans,cnt);
        cnt=0;
    }
    cout<<ans<<endl;
    return 0;
}