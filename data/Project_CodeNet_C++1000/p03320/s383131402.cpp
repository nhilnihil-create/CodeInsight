#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[MAXN];
char S[MAXN];

int digitsum(ll num)
{
    ll res = 0;
    while(num){
        res+=(num%10);
        num/=10;
    }
    return res;
}

void getnxt(long long &c)
{
    ll cur;
    ll n;

	for(ll i=1;;i*=10) {
        cur = c/i%10;
		if(cur==9) continue;
        n = c-cur*i;
        n += 9*i;
		if(c*digitsum(n)<=n*digitsum(c)) return;
		c=n;
	}
}

int main()
{
    ll n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k;

    ll res = 1;

    while(k--){
        cout<<res<<"\n";
        res++;
        getnxt(res);
    }


    return 0;
}
