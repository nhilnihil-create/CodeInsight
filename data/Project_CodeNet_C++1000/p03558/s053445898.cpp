#include<stdio.h>
#include<queue>
#include<math.h>
#include<time.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<stack>
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define lowbit(a) a&(-a)
#define PI acos(-1)
#define shortime(a)  std::ios::sync_with_stdio(a);
using  namespace std;
//const LL mod=1e9+7;
//long long cmp(node a,node b){ if(a.x==b.x) return a.r>b.r;return a.x>b.x;}
LL  quick(LL x,LL n,LL mod){ LL ans=1,temp=x; while(n){if(n%2==1){ ans=(ans*temp)%mod;} n/=2;temp=temp*temp%mod;}return ans%mod;}
int maxn (int a,int b,int c){return max(max(a,b),max(b,c));}
LL min(LL a,LL b) {return a<b?a:b;}
int gcd (int a,int b){return b==0?a:gcd(b,a%b);}
typedef pair <int ,int >node;
deque<node> Q;
int main()
{
   int n;
   scanf("%d",&n);
   node x;
   int vis[100005]={0};
   x.first=1;x.second=1;
   Q.push_front(x);
   while (!Q.empty())
   {
       node x=Q.front();
       Q.pop_front();
       if(vis[x.first]) continue;
       vis[x.first]=1;
       if(x.first==0) {
        printf("%d\n",x.second);
        return 0;
       }
       node temp=x;
       temp.first=(x.first*10)%n;
       Q.push_front(temp);
       temp=x;
       temp.first=(x.first+1)%n;
       temp.second++;
       Q.push_back(temp);
   }
   return 0;
}
