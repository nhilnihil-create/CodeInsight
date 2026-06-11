#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
int NOE(){
    cout<<-1<<endl;
    return 0;
}

unordered_map<ll,ll> mas;
#define N 100010
vector<ll> g[N];
ll n,d[N],s[N];
void AddEdge(ll a,ll b){
    s[b]+=s[a];
    g[a].push_back(b);
    g[b].push_back(a);
}

class Judge{public:
    ll f[N],s[N];
    void dfs(ll x,ll bef){
	ll res=0,sum=1;
	for(auto y:g[x]){
	    if(y==bef)continue;
	    dfs(y,x);
	    res+=f[y];
	    sum+=s[y];
	}
	s[x]=sum;
	f[x]=res+sum-1;
    }
    bool Main(){
	dfs(0,-1);
	return d[0]==f[0];
    }
};

unordered_map<ll,ll> ans;
int main(){
    cin>>n;
    lol(i,n){
	cin>>d[i];
	s[i]=1;
	ans[d[i]]=i+1;
    }
    sort(d,d+n,greater<ll>());
    lol(i,n)mas[d[i]]=i;
    lol(i,n-1){
	ll to=d[i]+2*s[i]-n;
	if(d[i]<=to)return NOE();
	if(mas.find(to)==mas.end())return NOE();
	AddEdge(i,mas[to]);
    }
    Judge jd;
    if(jd.Main()==0)return NOE();
    lol(i,n){
	for(auto x:g[i]){
	    if(i<x)cout<<ans[d[i]]<<" "<<ans[d[x]]<<endl;
	}
    }
    return 0;
}
