#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
typedef long long ll;

typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.1415926535897932384626;
long long int mod = 1000000007;

vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "RULD";
//↓,→,↑,←

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,a,b) for(i=a;i<=b;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll abc,ll bed){
    //abcのbed乗を計算する
    if(bed==0){return 1;}
    else{
        ll ced = rui(abc,bed/2);
        ced *= ced;
        ced %= mod;
        if(bed%2==1){ced*=abc; ced%=mod;}
        return ced;
    }
}



ll i,j,k,ii,jj;
ll n,m,num;
ll a,b,c,e,f,g,h;
ll x[800005],y[800005],z[900005];
ll d[800005],dp[500005];
ll vnum = 0,sum;
bool dame;
bool check[500005];


void unite(ll a,ll b){
    x[vnum] = a;
    y[vnum] = b;
    G[a].pb(b);
    G[b].pb(a);
    vnum++;
}

void dfs(ll v,ll dpn){
    if(check[v]){
        return;
    }else{
        sum += dpn;
        check[v] = true;
        for(int i=0;i<G[v].size();i++){
            if(!check[G[v][i]])dfs(G[v][i],dpn + 1);
        }
    }
}
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>d[i];
        z[i] = d[i];
    }
    sort(d,d+n);
    for(i=0;i<n;i++){
        z[i] = (lb(d,d+n,z[i]) - d) * 100001 + i;
    }
    sort(z,z+n);
    //reverse(d,d+n);
    for(i=n-1;i>=1;i--){
        //大きい数字から見て行くよ
        dp[i]++;
        num = d[i] - n + 2 * dp[i];
        a = lb(d,d+n,num) - lb(d,d+n,-1);
        if(d[a] != num || a >= i){
            dame = true;
            break;
        }else{
            dp[a] += dp[i];
            unite(a+1,i+1);
        }
    }
    sum = 0;
    dfs(1,0);
    //p(sum);
    if(sum != d[0]){
        dame = true;
    }
    if(dame){
        p(-1);
        return 0;
    }else{
        for(i=0;i<vnum;i++){
            pe(z[x[i]-1]%100001 + 1);p(z[y[i]-1]%100001 + 1);
        }
    }
    return 0;
}

