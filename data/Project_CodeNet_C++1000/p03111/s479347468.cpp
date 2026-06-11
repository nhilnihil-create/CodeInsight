#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

vector<int> l;
int n;
int ret=1e9;
void dfs(int x,int y,int z,int a,int b,int c,int i,int ans){
    if(i==n){
        if(a==0||b==0||c==0) return;
        int res=ans+abs(x-a)+abs(y-b)+abs(z-c);
        chmin(ret,res);
        return;
    }
    dfs(x,y,z,a+l[i],b,c,i+1,a?ans+10:ans);
    dfs(x,y,z,a,b+l[i],c,i+1,b?ans+10:ans);
    dfs(x,y,z,a,b,c+l[i],i+1,c?ans+10:ans);
    dfs(x,y,z,a,b,c,i+1,ans);
}
signed main(){
    int a,b,c; cin >> n >> a >> b >> c;
    l.resize(n);
    rep(i,n) cin >> l[i];
    dfs(a,b,c,0,0,0,0,0);
    cout << ret << endl;
}

