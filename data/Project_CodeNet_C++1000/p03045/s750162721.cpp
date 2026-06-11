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

vi p(MAXN),r(MAXN,0);

int dsu_find(int v){
    if(v==p[v]) return v;
    else return p[v]=dsu_find(p[v]);
}

void dsu_merge(int a,int b){
    a=dsu_find(a);
    b=dsu_find(b);
    if(r[a]<r[b]) swap(a,b);
    p[b]=a;
    r[a]++;
}

int main(){
    rapgame
    //freopen("brokeday.in", "r", stdin);
    //freopen("richday.out", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--){
        read2(n,m);
        fr(i,n) p[i+1]=i+1;
        fr(i,m){
            read2(a,b);read(c);
            dsu_merge(a,b);
        }
        set <int> ans;
        fr(i,n){
            ans.insert(dsu_find(i+1));
        }
        cout << ans.size();
    }
    return 0;
}