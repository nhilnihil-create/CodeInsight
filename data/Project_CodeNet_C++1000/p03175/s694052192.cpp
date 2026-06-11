#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4 , MOD = 1e9 + 7;
int n;
vector<int> adj[N];
int memo[N][2];
int add(int a, int b){
   a += b;
   while(a >= MOD)
      a -= MOD;
   while(a < 0)
      a += MOD;
   return a;
}

int mul(int a , int b){
   return (1ll * a * b) % MOD;
}

int solve(int u , int s , int p){

   int &ret = memo[u][s];
   if(~ret)
      return ret;
   ret = 1;
   for(int c : adj[u]){
      if(c == p)continue;
      int cr = solve(c , 0 , u);
      if(!s)cr = add(cr , solve(c , 1 , u));
      ret = mul(ret , cr);
   }
   return ret;
}
int main() {
#ifndef ONLINE_JUDGE
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n;
   for(int i = 1 ; i < n ; ++i){
      int u , v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   memset(memo , -1 , sizeof(memo));
   cout << add(solve(1 , 0 , -1) , solve(1 , 1 , -1)) << "\n";
}