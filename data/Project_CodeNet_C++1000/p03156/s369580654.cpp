#include<bits/stdc++.h>
#define mod 1000000007
#define f first
#define mt make_tuple
#define s second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define eps 1e-7
#define endl "\n"
#define ll long long int
#define mp make_pair
#define p_q priority queue

using namespace std;
     

     int a[100005];
int vis[100005]={0};
 vector< int > adj[100005];

    
// int power(int x, unsigned int y) 
// { 
//     int temp; 
//     if( y == 0) 
//         return 1; 
//     temp = power(x, y/2); 
//     if (y%2 == 0) 
//         return temp*temp; 
//     else
//         return x*temp*temp; 
// } 
     

bool vowl(char c)
{
  return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
 
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;    
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;  
        x = (x*x) % p; 
    } 
    return res; 
} 
bool check(ll n, ll p) 
{ 
    if (power(n, (p-1)/2, p) == 1) 
       return true; 
  
    return false; 
} 

int dfs(int source,int vertex_covered)
{
  vis[source]=1;
  if(adj[source].size()==1)
  {
    int v=adj[source][0];
    if(vis[v])
    {
      a[source]=1; 
      return 1;// means i cannot remove that edge
    }
  }

  for(int j=0;j<adj[source].size();j++)
  {
    if(!vis[adj[source][j]])
    {
      vertex_covered+=dfs(adj[source][j],1);
    }
  }
  //cout<<source<<"--->"<< vertex_covered<<endl;
   
   a[source]= vertex_covered;
   return vertex_covered;

    

}
 
 
int main()
{
    fast;
    int t=1;
   // cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int a,b,c1=0,c2=0,c3=0;
      cin>>a>>b;
      for(int i=0;i<n;i++)
      {
        int x;
        cin>>x;
        if(x<=a)
        {
          c1++;
        }
        else if(x>=a+1 && x<=b)
        {
          c2++;
        }
        else if(x>=b+1)
        {
          c3++;
        }
      }
      int ans=min(min(c1,c2),c3);
      cout<<ans<<endl;
      
    }




    return 0;  
}