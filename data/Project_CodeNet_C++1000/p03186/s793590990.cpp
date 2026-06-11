// CODE by Kazhybay Askar
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define iter   set<int>::iterator
#define f      first
#define s      second
#define pb     push_back
#define pf     push_front
#define mp     make_pair
#define cont   continue
#define ll     long long
#define Speed  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define sz     size()
#define all(x) x.begin(),x.end()
#define cont   continue
#define r0     return 0
#define endl   '\n'

const int MAXN = 1e5  + 7;
const int MOD  = 1e9  + 7;
const int INF  = 1e9  + 7;
const ll  MINF = 1e18 + 7;
const int EPS  = 1e-6;
const int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
const double pi = acos(-1.0);


typedef long double   ld;
typedef pair<ll,ll>   pll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;

vector<int>g[MAXN],v;
bool used[MAXN];
ll n,m,k,cnt,sum,ans,mx,mn=INF;
bool y;

void freopen(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
}

ll a,b,c;
void solve(){
	cin>>a>>b>>c;
    mn=min(b,c);
    cnt+=mn*2;
    b-=mn;
    c-=mn;
    mn=min(a,c);
    cnt+=mn;
    a-=mn;
    c-=mn;
    cnt+=b;
    if(c>0){
        cnt++;
    }
    cout<<cnt;
}

int main(){
	Speed;
	ll T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	r0;
}


