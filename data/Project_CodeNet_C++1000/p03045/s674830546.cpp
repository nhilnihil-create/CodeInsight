/******************************************************************************
 
рассвет. 
 
*******************************************************************************/
#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define rapgame ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define eb emplace_back
#define vi vector <int>
#define vlli vector <lli>
#define vulli vector <ulli>
#define vchar vector <char>
#define vstr vector <string>
#define vb vector <bool>
#define fst first
#define sec second
#define all(a) (a).begin(),(a).end()
#define srt(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define vpii vector <pair <int,int> >
#define pii pair <int,int> 
#define vplli vector <pair <lli,lli> >
#define vvi vector <vector <int> >
#define vvlli vector <vector <lli> >
#define vvpii vector <vector <pair <int,int>> >
#define fr(i,n) for (int i = 0; i < (n); ++i)
#define frbig(i,n) for (lli i = 0; i < (n); ++i)
#define fra(i,a,n) for (int i = a; i < (n); ++i)
#define run(c,s) for(auto c:s) 
#define read(n) int n; cin >> n;
#define readchar(n) char n; cin >> n;
#define readstr(n) string n; cin >> n;
#define readarr(a,n) fr(i,n) cin >> a[i];
#define read2(x,y) int x,y; cin >> x >> y;
#define read2ll(x,y) long long int x,y; cin >> x >> y;
#define readll(n) lli n; cin >> n;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define print_array(x) fr(i,x.size()) cout << x[i] << " ";
using namespace std;
 
const lli MOD=1e9+7;
const lli MAXN=1e5+1;
const ld PI=acos(-1);

vvi g(MAXN);
bool used[MAXN];

void dfs(int v){
    used[v]=1;
    run(to,g[v]){
        if(!used[to]){
            dfs(to);
        }
    }
}

int main(){
    rapgame
    //freopen("brokeday.in", "r", stdin);
    //freopen("richday.out", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--){
        read2(n,m);
        int ans=0;
        fr(i,m){
            read2(a,b);read(c);
            g[a].pb(b);
            g[b].pb(a);
        }
        fr(i,n){
            if(!used[i+1]){
                dfs(i+1);
                ans++;
            }
        }
        cout << ans;
    }
    return 0;
}