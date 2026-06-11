#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m)
{
    ll  ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

vector<int>v[100005];
bool vis[100005];
int l[100005];
int n;

int dfs(int index,int length,int parent){
    if(l[index]!=-1){
        return l[index];
    }
    vis[index]=true;
    if(v[index].size()==0){l[index]=1; return 1;}
    
    for(int i=0;i<v[index].size();i++){
        if(v[index][i]!=parent)
          l[index]=max(l[index],1+dfs(v[index][i],length,index));
    }
    return l[index];
}

int main()
{
	IOS;
	int t=1; //cin>>t;
	while(t--){
	  int m;
	  cin>>n>>m;
	  for(int i=1;i<=n;i++) l[i]=-1,vis[i]=false;
	  for(int i=0;i<m;i++){
	      int x,y;
	      cin>>x>>y;
	      v[x].push_back(y);
	  }
	  for(int i=1;i<=n;i++){
	      if(!vis[i]){
	          dfs(i,1,0);
	      }
	  }
	  int ans=0;
	  for(int i=1;i<=n;i++) ans=max(ans,l[i]);
	  cout<<ans-1;
	  cout<<"\n";
	}    

}