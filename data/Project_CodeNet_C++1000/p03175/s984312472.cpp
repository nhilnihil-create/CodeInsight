#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7; 
const int N = 1e5+1; 
int n; 

vector<int> tree[N];
vector<int> white(N,0),black(N,0); 

void dfs(int node, int parent)
{ 
 
    long w_ways = 1, b_ways = 1; 
    for(int child: tree[node])
    {
        if(child != parent)
        {
            dfs(child,node);
            
            w_ways = w_ways * ( ( 0l +  white[child] + black[child] ) % mod ) % mod;
            b_ways = ( b_ways*white[child] ) % mod; 
            
        }
    }
    
    white[node] = w_ways;
    black[node] = b_ways; 
    
    
}


void solve()
{
       cin >> n;
       
       for(int i = 0 ; i < n-1; i ++)
       {
           int x,y; cin >> x >> y;
           
           tree[x].push_back(y);
           tree[y].push_back(x);
       }
       
       dfs(1,-1); 
       cout <<  ( white[1] + black[1] ) % mod ; 
}

int main()
{

	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);

	 solve();
	 return 0;
}

/**


*/


