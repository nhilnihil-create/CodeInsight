#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define endl "\n"
#define M 1000000007
#define boost
#define push_back push
#define pop_back pop
#define fo(i,n)   for (size_t i = 0; i < n; i++)
#define fo1(i,n)   for (size_t i = 1; i <= n; i++)
template<class _T>inline void read(_T &_a)
{
    bool f=0; char _c=getchar(); _a=0;
    while(_c<'0'||_c>'9'){ if(_c=='-') f=1; _c=getchar(); }
    while(_c>='0'&&_c<='9'){ _a=(_a<<3)+(_a<<1)-'0'+_c; _c=getchar(); }
    if(f) _a=-_a;
}
int price[100001];
int dp[100001];

int cost(int x){
    
    if(x==1)
    return dp[x]=0;

    if(x==2)
   return dp[x]= abs(price[2]-price[1]);

  else{ 
  if(dp[x]!=-1)
  return dp[x];

 else
return dp[x]= std ::min(cost(x-1)+ abs(price[x]-price[x-1]),cost(x-2)+abs(price[x]-price[x-2])) ;
  } 
   
}
//ll T;

int main()
{  
   /* ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
      for(read(T);T;--T)*/
   {
    memset(dp,-1,sizeof(dp));
    int n ; read(n);

    fo1(i,n)
    read(price[i]);

    cout<<cost(n);
   }

return 0;
}