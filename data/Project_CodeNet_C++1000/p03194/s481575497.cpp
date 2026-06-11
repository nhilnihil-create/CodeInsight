#include <bits/stdc++.h>

#define int         long long
#define uint        unsigned int
#define ld          long double
#define showoff     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb          push_back
#define pii         pair<int,int>
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define RFOR(i,a,b) for(int i=a;i>b;--i)
#define f           first
#define se          second
#define maxn        200005
#define all(v)      v.begin(),v.end()
#define sz(x)       (int)x.size()
#define mod         1000000007
#define pqueue      priority_queue<int>
#define pdqueue     priority_queue< int,vector<int> ,greater< int >>

using namespace std;


//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const int md = 998244353;

int power(int a,int n)
{
    if(n == 1)return a;
    if(n == 0)return 1;
    if(n&1)return a*power(a*a,n/2);
    return power(a*a,n/2);
}
//int n,m,k;

signed main()
{
    showoff;
    //cin >> n >> m >> k;
    int n,p,p1;
    cin >> n >> p;
    if(n == 1){cout << p;return 0;}
    vector<pii >fact;
    p1 = p;
    for(int i = 2;i <= 10000005;++i){
    if(i > p)break;
    if(p%i != 0)continue;
    int c = 0;
    while(p%i == 0){
    p /= i;
    ++c;
    }
    fact.pb({i,c});
    }
    int ans = 1;
    for(auto &x:fact){
    ans *= power(x.f,x.se/n);
    }
    cout << ans;
    return 0;
}
