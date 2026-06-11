#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;

#define FOR(k,a,b) for(int k=(a); k<=(b); ++k)
#define IFOR(k,a,b) for(int k=(a); k>=(b); --k)
#define REP(k,a) for(int k=0; k<(a);++k)
#define IREP(k,a) for(int k=a-1; k>=(0);--k)
#define SZ(a) int((a).size())
#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define x first
#define y second
#define INF 1000000001
#define INFLONG 1000000000000000000
#define MOD 1000000007
#define MAX 100
#define ITERS 100
#define MAXM 200000
#define MAXN 1000000
#define PI 3.1415926535897932384626
#define ERR -987654321
#define MEM(a,b) memset(a,b,sizeof(a));
#define read1(a) scanf("%d",&a)
#define read2(a,b) scanf("%d%d",&a,&b)
#define read3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define readl1(a) scanf("%lld",&a)
#define readl2(a,b) scanf("%lld%lld",&a,&b)
#define readl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

int n,m;
ll x,y;
vector<pll> v;
ll dist[35];

string solve(ll x, ll y) {
    string res;
    // cout<<"For ("<<x<<","<<y<<")"<<endl;
    IFOR(i,m,1) {
        int s = dist[i]-1;
        if((abs(x-dist[i]) + abs(y)) <= s && (abs(x-dist[i]) + abs(y))%2 == 1) {
            res += 'R';
            x -= dist[i];
        } else if((abs(x) + abs(y-dist[i])) <= s && (abs(x) + abs(y-dist[i]))%2 == 1) {
            res += 'U';
            y -= dist[i];
        } else if((abs(x+dist[i]) + abs(y)) <= s && (abs(x+dist[i]) + abs(y))%2 == 1) {
            res += 'L';
            x += dist[i];
        } else {
            res += 'D';
            y += dist[i];
        }
        // cout<<x<<" "<<y<<endl;
    }
    if(x == 1) res += 'R', x-=1;
    else if(x == -1) res += 'L', x+=1;
    else if(y == 1) res += 'U', y-=1;
    else res += 'D', y+=1;
    // cout<<x<<" "<<y<<endl;
    // cout<<"------------------------------------"<<endl;
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	// int rn = uniform_int_distribution<int>(0, MAXN)(rng);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    cin>>n;
    REP(i,n) {
        cin>>x>>y;
        v.PB(MP(x,y));
    }

    int parity = (abs(v[0].x) + abs(v[0].y))%2;
    //cout<<parity<<endl;
    FOR(i,1,v.size()-1) {
        if(parity != (abs(v[i].x) + abs(v[i].y))%2) {
            cout<<"-1";
            return 0;
        }
    }

    m = 30;
    dist[0] = 1ll;
    FOR(i,1,m) dist[i] = dist[i-1]*2ll;

    vector<string> str;
    REP(i,v.size()) {
        if(parity%2) str.PB(solve(v[i].x, v[i].y));
        else str.PB(solve(v[i].x-1, v[i].y));
    }

    if(parity%2) {
        cout<<(m+1)<<endl;
        REP(i,m+1) cout<<dist[i]<<" "; cout<<endl;
        REP(i,str.size()) {
            reverse(ALL(str[i]));
            cout<<str[i]<<endl;
        }
    } else {
        cout<<(m+2)<<endl;
        REP(i,m+1) cout<<dist[i]<<" "; cout<<"1"; cout<<endl;
        REP(i,str.size()) {
            reverse(ALL(str[i]));
            cout<<str[i]<<"R"<<endl;
        }
    }
	return 0;
}




