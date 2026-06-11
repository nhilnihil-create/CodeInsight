#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
vector<int> v[200001];
int c=0;
int d[200001];
string s;
bool used[200001];
void dfs(int now,int par){
    if(c)return;
    int num=(d[now]+1)%4;
    used[now]=true;
    //cout<<now<<" "<<d[now]<<" "<<num<<endl;
    rep(i,0,v[now].size()){
        int ne=v[now][i];
       // cout<<ne<<" "<<s[ne-1]<<" "<<num<<" "<<d[ne]<<endl;
        if(num<=1){
            if(s[ne-1]=='A'){
                if(d[ne]==num||d[ne]==5){
                    c=1;
                    //cout<<ne<<" "<<now<<" "<<par<<endl;
                    //rep(j,1,91)cout<<d[j]<<" ";
                    //cout<<endl;
                    return;
                }
                else{
                    if(par==ne)continue;
                    if(ne==now){
                        d[ne]=num+4;
                    }
                    else d[ne]=num;
                    dfs(ne,now);
                    d[ne]=-1;
                }
            }
        }
        else{
            if(s[ne-1]=='B'){
                if(d[ne]==num||d[ne]==7){
                    c=1;
                    //cout<<ne<<" "<<now<<" "<<par<<endl;
                    return;
                }
                else{
                    if(par==ne)continue;
                    if(ne==now){
                        d[ne]=num+4;
                    }
                    else d[ne]=num;
                    dfs(ne,now);
                    d[ne]=-1;
                }
            }
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    cin>>s;
    set<int> st[n+1];
    rep(i,0,m){
        int a,b;cin>>a>>b;
        st[a].insert(b);
        st[b].insert(a);
    }
    rep(i,1,n+1){
        for(auto itr=st[i].begin();itr!=st[i].end();itr++){
            v[i].push_back(*itr);
            //cout<<v[i].back()<<" ";
        }
        //cout<<endl;
    }
    fill(d,d+n+1,-1);
    fill(used,used+n+1,false);
    rep(i,1,n+1){
        if(used[i])continue;
        d[i]=0;
        dfs(i,-1);
        d[i]=-1;
    }
    if(c)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    rep(i,1,n+1){
        //cout<<i+1<<" "<<s[i]<<" ";
        //cout<<i<<endl;
        //rep(j,0,v[i].size())cout<<v[i][j]<<" ";
        //cout<<endl;
    }
}
