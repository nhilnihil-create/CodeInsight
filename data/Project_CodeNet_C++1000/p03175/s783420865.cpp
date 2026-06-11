#include<bits/stdc++.h>
using namespace std;
long int mod=1000000007;
bool visited[100000+10]={false};
long int ans_b[100000+10];
long int ans_w[100000+10];
vector<long int> tree[100000+10];
 
vector<long int> dfs(long int u)
{
  visited[u]=true;
  long int b=1,w=1;
  for(long int i:tree[u])
  {
    if(!visited[i])
    {
      vector<long int> x=dfs(i);
      b=(b*x[1])%mod;
      w=(w*(x[0]+x[1])%mod)%mod;
    }
  }
  vector<long int> k;
  k.push_back(b);
  k.push_back(w);
  return k;
}
 
int main()
{
	long int n;
  	cin>>n;
  memset(ans_b,-1,sizeof ans_b);
  memset(ans_w,-1,sizeof ans_w);
  for(long int i=1;i<n;i++)
  {
  	long int u,v;
    cin>>u>>v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  vector<long int> k=dfs(1);
  cout<<(k[0]+k[1])%mod<<endl;
}