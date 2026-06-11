#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
#define fori(i,a,b) for(int i=(a);i<(int)(b);i++)
#define repi(i,n) fori(i,0,n)
#define forr(i,a,b) for(int i=int(b-1);i>=int(a);i--)
#define repr(i,n) forr(i,0,n)
#define all(x) (x).begin(),(x).end()
#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define pcnt __builtin_popcount
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

#define MAX 10010
vector<int> g[MAX];
int s[MAX],c[MAX];
int idx=0;
void dfs(int i,int p){
    s[i]=c[idx++];
    for(int x:g[i]){
        if(x==p)continue;
        dfs(x,i);
    }
}
void solve(){
    int n;
    cin>>n;
    repi(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    repi(i,n)cin>>c[i];
    
    sort(c,c+n,greater<int>());
    dfs(0,-1);

    ll sum=0;
    fori(i,1,n)sum+=c[i];
    cout<<sum<<endl;
    repi(i,n){
        if(i>0)cout<<" ";
        cout<<s[i];
    }
    cout<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
