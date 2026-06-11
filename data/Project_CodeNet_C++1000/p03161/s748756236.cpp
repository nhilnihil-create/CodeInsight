#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define int long long
#define float double
#define MAX 100005
const int  mod = 99824435300;
#define LMT 100000000000
#define int long long 
#define pb push_back 
#define lp(i,n) for( i=0;i<n;i++) 
#define lop(j,n)for( j=0;j<n;j++)
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
#define m_p make_pair
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define minheap priority_queue<int,vector<int>,greater<int>>
#define maxheap priority_queue<int>
#define kickstart  cout<<"Case #"<<cc<<": "
#define pair_pq priority_queue<pii,vector<pii>,greater<pii>>
#define ff first
#define ss second
#define pff pair<float,float>
#define piii pair<int,pii>
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = a * a;
        b >>= 1;
    }
    return res;
}


int fact(int a){int ans=1;
  while(a>1){ans=(ans*a)%mod;a--;}return ans;
}

void solve(){
int i,j,k,l=0,r=mod,m,diff=0,n,q;
cin>>n>>k;int a[n],dp[n];lp(i,n)cin>>a[i],dp[i]=LMT;
dp[0]=0;dp[1]=abs(a[1]-a[0]);
for(i=2;i<n;i++)
  for(int j=1;i-j>=0 && j<=k;j++)
  dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);//dp[i-1]+abs(a[i]-a[i-1]));
cout<<dp[n-1]<<endl;
}
 int32_t main(){
  fastio
 #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
 #endif
int t=1;
//cin>>t;
while(t--)solve();
return 0;
 }
