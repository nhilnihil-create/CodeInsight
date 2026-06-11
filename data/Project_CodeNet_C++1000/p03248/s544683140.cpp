#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ld,ld> id;

#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define ROF(i, a, b) for(int i=(a); i>=(b); i--)
#define MEM(x, v) memset(x, v, sizeof(x))
#define FILL(x, n, v) fill(x, x+n, v);
#define ALL(x) x.begin(), x.end()
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define f first
#define s second
#define ins insert
#define e emplace
#define eb emplace_back
#define ef emplace_front
#define p push
#define pf push_front
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define ft front
#define bk back
#define pp pop
#define ppb pop_back
#define ppf pop_front

#define db cout<<"YEET\n";
#define ct(x) cout<<x<<'\n';

const ll MOD = 1e9+7; //998244353
const ll MAXN = 2e5+5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);

int main(){
    FAST
    string ss;
    cin >> ss;
    ll n = ss.length();

    string s1 = ss.substr(0,n-1);
    string s2 = ss.substr(0,n-1);
    reverse(ALL(s2));
    
    bool valid=1;
    vector<ii> ans;
    if (s1 != s2) valid=0;
    else if (ss[n-1]=='1' || ss[0]=='0') valid=0;
    else {
        ll curnode=1, nextnode=2;

        FOR(i,0,n-2){
            if (s1[i] == '1'){
                ans.eb(curnode, nextnode);
                curnode = nextnode++;
            } else {
                ans.eb(curnode, nextnode);
                nextnode++;
            }
        }
    }
    if (valid){
        FOR(i,1,n-1){
            cout << ans[i-1].f << " " << ans[i-1].s << '\n';
        }
    } else cout << "-1";
}