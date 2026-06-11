#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define f           first
#define s          second
#define sz(x)       (int)x.size()
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep0(a,n)  for(int i=0;i<n;i++)cin>>a[i]
#define si(x)       cin>>x
#define sii(x,y)    cin>>x>>y
#define siii(x,y,z) cin>>x>>y>>z
#define ahell   998244353
#define hell 1000000007
#define N1 100001
#define fl 1.0000000000
//#define mod 998244353
#define cntbit(a) __builtin_popcountl(a)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int N=200001;
int st[4*N+3];

    //Write reqd merge functions

    //Handle lazy propagation appriopriately

    int  Query(int node, int L, int R, int i, int j)
    {
        if(j<L || i>R)
            return 0;
        if(i<=L && R<=j)
            return st[node];
        int M = (L + R)/2;
        int left=Query(node*2, L, M, i, j);
        int right=Query(node*2 + 1, M + 1, R, i, j);
        //data cur;
      return max(left,right);

    }
    void pUpdate(int node, int L, int R, int pos, int val)
    {

        if(L == R)
        {
            st[node]=val;
            return;
        }
        int M = (L + R)/2;
        if(pos <= M)
            pUpdate(node*2, L, M, pos, val);
        else
            pUpdate(node*2 + 1, M + 1, R, pos, val);
      st[node]=max(st[2*node],st[2*node+1]);
        //merge(st[node], st[node*2], st[node*2 + 1]);
    }
main()
{
  ios
int n,m,i;
int j;
int u,v,q;
int test=1;
//si(test);

while(test--)
{
  cin>>n;
  int h[n],a[n];
  for(i=0;i<n;i++)
    cin>>h[i];
for(i=0;i<n;i++)
    cin>>a[i];
int ans=0;
//init(200001);
for(i=0;i<n;i++)
{
    int t1=Query(1,1,n,1,h[i]-1);
    ans=max(ans,t1+a[i]);
    pUpdate(1,1,n,h[i],t1+a[i]);
}
cout<<ans;

}

}
