///              B I S M I L L A H I R  R A H M A N I R  R A H I M

#include<bits/stdc++.h>
using namespace std;
typedef bool                   boo;
typedef int                    li;
typedef long                   il;
typedef unsigned long          ul;
typedef long long int          ll;
typedef unsigned long long     ull;
typedef double                 dd;
typedef string                 str;
#define vli                    vector<li>
#define vll                    vector<ll>
#define sli                    set<li>
#define sll                    set<ll>
#define pli                    pair<li, li>
#define pll                    pair<ll, ll>
#define vpi                    vector<pair<li, li>>
#define vpl                    vector<pair<ll, ll>>
#define mpl                    map<ll, ll>
#define wt                     ll t; cin>>t; while(t--)
#define input(a,n)             for(int i=0;i<n;i++) cin>>a[i];
#define lp(a, i, b)            for(ll i=a; i<b; i++)
#define rlp(a, i, b)           for(ll i=a; i>=b; i--)
#define sz(x)                  x.size()
#define len(z)                 z.begin(), z.end()
#define ci(x)                  cin>>x;
#define co(x)                  cout<<x nl
#define mem(z, l)              memset(z, l, sizeof(z))
#define MP                     make_pair
#define pb                     push_back
#define F                      first
#define S                      second
#define nl                     <<endl
#define nll                    cout<<endl
#define sp                     <<" "<<
#define sl                     <<" "
#define cy                     cout<<"YES"<<nl
#define cn                     cout<<"NO"<<nl
#define rn                     return
#define good_bye               return 0
#define PI                     3.1415926536
#define gcd(a,b)               __gcd(a,b)
#define lcm(a,b)               (a*(b/gcd(a,b)))
#define faster                 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define input_txt()            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
const double eps=              1e-9;
const int inf=                 2000000000;
const ll infLL=                9000000000000000000;
//ll Pow(ll P, ll Q)           { ll R=1; for(ll I=1; I<=Q; I++) R*=P; rn R; }
//void dfs(ll K)               { vis[K]=true; for(auto J: v[K]) { if(!vis[J]) dfs(J); } }
//void seive(ll MX)            { S.pb(2); for(ll I=3; i<=MX; i+=2) { if(!vis[I]) { S.pb(I); for(ll J=I*I; j<=MX; J+=(2*I)) vis[J]=false; } } }
//bool isPrime(ll n)           { if(n%2==0) rn false; for(ll i=3; i*i<=n; i+=2) { if(n%i==0) rn false; } rn true; }
//----------------------------------------LET'S BEGIN-----------------------------------------------------------------------
const int mX = 1e6+123;
str s, s1, s2;

void case_i()
{
    ci(s);
    s1+=s[5]; s1+=s[6];
    s2+=s[8]; s2+=s[9];
    if(stoi(s1)>4) cout<<"TBD" nl;
    else if(stoi(s1)<4) cout<<"Heisei" nl;
    else
    {
        if(stoi(s2)<=30) cout<<"Heisei" nl;
        else cout<<"TBD" nl;
    }
}

int main()
{
    faster;
//    input_txt();
//    wt
      case_i();
    good_bye;
}
///           _5_4_8_8_1_9_                ///
