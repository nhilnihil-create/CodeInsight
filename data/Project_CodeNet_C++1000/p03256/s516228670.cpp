#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
vector<int> E[400000];
int flag[400000];
int N,M;
bool dfs(int x){
    if(flag[x]==1) return true;
    flag[x]=1;
    for(int &to : E[x]){
        if(flag[to]>=0&&dfs(to)) return true;
    }
    flag[x]=-1;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    string s;
    cin>>s;
    rep(i,0,M){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a==b){
           E[N+a].pb(b);
        }
        else if(s[a]==s[b]){
            E[N+a].pb(b);
            E[b+N].pb(a);
        }
        else{
            E[a].pb(b+N);
            E[b].pb(a+N);
        }
    }
    rep(i,0,2*N){
        if(flag[i]==0){
            if(dfs(i)){
                cout <<"Yes"<<"\n";
                return 0;
            }
        }
    }
    cout <<"No"<<"\n";
}