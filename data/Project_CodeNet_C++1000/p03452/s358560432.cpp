#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef string S;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define ft first
#define sd second
#define elif else if
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mp make_pair
#define fr(i,n)for(ll i=0;i<(n);i++)
#define ifr(i,n)for(ll i=(n)-1;i>=0;i--)
const int MOD = 1e9+7;
const ll INF =1e18;
ll dp[100010];

int main(){
    ll n,m;cin >> n >> m;
    vector<vp> x(n);
    fr(i,m){
        ll l,r,d;cin >>l >>r>>d;
        l--;
        r--;
        x[l].pb(mp(r,d));
        x[r].pb(mp(l,-d));
    }
    fr(i,n) dp[i] = INF;
    fr(i,n){
        if(dp[i]==INF){
            queue<int> que;
            que.push(i);
            dp[i]=0;
            while(!que.empty()){
                int v=que.front();que.pop();
                fr(j,x[v].size()){
                    P p=x[v][j];
                    int to=p.first,c=p.second;
                    if(dp[to]==INF){
                        dp[to] = dp[v] + c;
                        que.push(to);
                    }
                    else if(dp[to]!=dp[v]+ c){
                        cout << "No" << endl;
                        return 0;
                    }
                }
                }
        }
    }
    cout << "Yes" << endl;
}