#include<bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}

#define FOR(a,b,c) for(int a=b, __c=c; a<=__c; ++a)
#define FORD(a,b,c) for(int a=b, __c=c; a>=__c; --a)
#define forv(a,b) for(auto &a:b)

#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)
#define reset(f,x) memset(f,x,sizeof(f))
#define fasty ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))

const int N=17;
int n,a[N][N],f[1<<N],c[1<<N];
int cur;

void dfs(int i,int x){
   if(i>n) f[cur]=max(f[cur], f[x]+c[cur^x]);
   else{
      dfs(i+1, x);
      if(bit(cur,i)) dfs(i+1, on(x,i));
   }
}

int32_t main(){
   fasty;

   cin>>n;
   FOR(i,1,n) FOR(j,1,n) cin>>a[i][j];

   FOR(p,1,(1ll<<n)-1){
      FOR(i,1,n) if(bit(p,i)){
         FOR(j,i+1,n) if(bit(p,j)){
            c[p]+=a[i][j];
         }
      }
   }

   reset(f,-127);
   f[0]=0;
   FOR(i,1,(1ll<<(n))-1){
      cur=i;
      dfs(1,0);
   }
   cout<<f[(1ll<<n)-1]<<'\n';
}
