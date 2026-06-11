#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define in(a)                       ll a; cin>>a;
#define in2(a,b)                    ll a,b; cin>>a>>b;
#define in3(a,b,c)                  ll a,b,c; cin>>a>>b>>c;
#define in4(a,b,c,d)                ll a,b,c,d; cin>>a>>b>>c>>d;
#define in5(a,b,c,d,e)              ll a,b,c,d,e; cin>>a>>b>>c>>d>>e;
#define lelo(b)                     for(auto &i:b)cin>>i;
#define ff                          first
#define ss                          second
#define call(v)                     v.begin(),v.end()
#define rall(v)                     v.rbegin(),v.rend()
#define show(x)                     for(auto t:x)cout<<t<<" ";
#define pb                          push_back
#define bhar(s,v)                   memset(s,v,sizeof(s))
#define endl                        "\n"                       
#define ce(x)                       cout<<x<<"\n";
#define nl                          cout<<endl;
#define jaldi                       ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dekh_lo                     ce("dekh_lo");
#define sz(x)                       (ll)x.size()
#define re                          return

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef pair<ll,ll> pii;
typedef vector<pii> vii;
typedef vector<ll> vi;

const ll mod=1e9+7;
const ll N=4e5+5;
ll i,j;

/*


*/

ll dp[1005][1005];
void solve(){
	bhar(dp,0);
    in2(h,w);
    std::vector<string> v(h); lelo(v);
    dp[0][0]=1;
    bool f=0;
    for(i=0;i<h;i++){
    	if(v[i][0]=='.'){
    		dp[i][0]=1;
    	}
    	else{
    		f=1;
    		break;
    	}
    }
    f=0;
    for(j=0;j<w;j++){
    	if(v[0][j]=='.'){
    		dp[0][j]=1;
    	}
    	else{
    		break;
    	}
    }
    for(i=1;i<h;i++){
    	for(j=1;j<w;j++){
    		if(v[i][j]=='.'){
    			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    		}
    	}
    }
    ce(dp[h-1][w-1]);
}

int32_t main(){
    // jaldi
    ll t; 
    // cin>>t;
    t=1;     
    while(t--){
        solve();
    }
}

/*


*/

  
