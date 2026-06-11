#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define M1 (ll)1000000007
#define M2 (ll)998244353
#define Pi 3.141592653
#define exp 2.71828
#define ll long long
#define ull unsigned long long 
#define pi pair<int,int>
#define pl pair<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define di deque<int>
#define dl deque<ll>
#define dii deque<pi>
#define dll deque<pl>
#define vvi vector<vi>
#define vvl vector<vl>
#define vii vector<pi>
#define vll vector<pl>
#define pb push_back
#define pp pop_back
#define pf push_front
#define pt pop_front
#define mp make_pair
#define in insert
#define er erase
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define rp(i,a,b) for(int i=a;i<b;i++)
#define rpt(i,a,b,t) for(int i=a;i<b&&t<1;i++)
#define rep(i,n) for(int i = 0 ; i<n ; i++)
#define rept(i,n,t) for(int i = 0 ; i<n&&t<1 ; i++)
#define repr(i,n) for(int i = n-1 ; i>=0 ; i--)
#define reprt(i,n,t) for(int i=n-1;i>=0&&t<1;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define SORT(v) sort(v.begin(),v.end())
struct lex_compare {public:
    bool operator() (const pl& lhs, const pl& rhs) const {
        if(lhs.ss==rhs.ss)
            return lhs.ff<rhs.ff;
        return (lhs.ss>rhs.ss);
    }
};
class trp{
    public:
        ll a,b,c;
        trp(){
            this->a=0;
            this->b=0;
            this->c=0;
        }
        trp(ll a,ll b,ll c){
            this->a=a;
            this->b=b;
            this->c=c;
        }
};
class node{public:
    ll index,a,l;
    ll d,h;
    node* mr_img;
    node* lf=NULL;
    node* rt=NULL;
    node* prt=NULL;
    vector<node*> v;
    ///////////////
    
    node(){
        index=0,a=0,l=0;
        d=1,h=0;
        mr_img=NULL;
        lf=NULL;
        rt=NULL;
        prt=NULL;
        ///////////////
        
    } 
    void adn(node* t){
        v.pb(t);
        this->l++;
    }
};
node* nnd(ll a){
    node* t = new node();
    t->a =a;
    return t;
}
ll pw(ll a, ll b,ll m){
    if(b==0) return 1;
    if(b%2==0)
        return (pw(a,b/2,m)*pw(a,b/2,m))%m;
    return (a*((pw(a,b/2,m)*pw(a,b/2,m))%m))%m;
}
ll gc(ll a,ll b){
    if(b==0)
        return a;
    return gc(b,a%b);
}
vector<string> splt(string x,char w){
    vector<string> v;
    string s;
    int l=x.length();
    rep(i,l){
        if(x[i]==w){
            v.pb(s);
            s="";
        }
        else{
            s.pb(x[i]);
        }
    }
    v.pb(s);
    return v;
}
void ioe(){
    freopen("in_3.txt","r",stdin);
    freopen("out_3.txt","w",stdout);
    freopen("er_3.txt","w",stderr);
}
////////////////*here we go*///////////////////
ll n,a[21][21]={},m[21][1<<21];
ll sl(ll x,ll y){
    if(x>n-1)
        return 1;
    if(m[x][y]!=-1)
        return m[x][y];
    m[x][y]=0;
    rep(i,n){
        if((a[x][i]==1)&&((y&(1<<i))==0)){
            m[x][y]+=sl(x+1,(y|(1<<i)));
            m[x][y]%=M1;
        }
    }
    return m[x][y];
}
void solve() {
    rep(i,21)rep(j,1<<21)
        m[i][j]=-1;
    cin>>n;
    rep(i,n)rep(j,n)
        cin>>a[i][j];
    cout<<(sl(0,0))<<"\n";
}
signed main()
{
    fast;
    //ioe();
    ll t=1;
    //cin>>t;
    ll f=t;
    while(f--){
        //cout<<"Case #"<<(t-f)<<": ";
        //cout<<t<<"\n";
        solve();
    }
}