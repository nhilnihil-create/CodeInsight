#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <iomanip>
#include <bitset>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define pi acos(-1)
#define mod 998244353 //1000000007
#define inf 1000000007
#define ll long long
#define ull unsigned long long
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
#define N 200005
#define _DEBUG
template <class U,class T> void Max(U &x, T y){if(x<y)x=y;}
template <class U,class T> void Min(U &x, T y){if(x>y)x=y;}
template <class T> void add(int &a,T b){a=(a+b)%mod;}
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;b>>=1;
    }
    return ans;
}
int pow(int a,int b,int c){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%c;
        a=1LL*a*a%c;b>>=1;
    }
    return ans;
}

vi g[N];
int d[N];
int bfs(int s, int n){
    queue<int>q;q.push(s);
    memset(d, -1, sizeof(d));
    d[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &v : g[u]){
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    rep(i, 0, n)if(d[i] > d[s]) s = i;
    return s;
}
int main(){
    //srand(time(NULL)+clock());
    int T,ca=0,k,i,j,m=0, K, n;
    scanf("%d", &n);
    rep(i, 1, n){
        scanf("%d %d", &j, &k);
        j--, k--;
        g[j].pb(k);
        g[k].pb(j);
    }
    int s = bfs(0, n);
    int t = bfs(s, n);
    K = d[t] + 1;
    if(K % 3 < 2){
        puts("First");
    }
    else{
        puts("Second");
    }
    //cerr<<(1.*clock()-start)/CLOCKS_PER_SEC<<"\n";
}

