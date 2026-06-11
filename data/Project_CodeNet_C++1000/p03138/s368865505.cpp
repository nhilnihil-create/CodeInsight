#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)
const ll INF=1e17;
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void  solve(){
  ll n,k;
     cin>>n>>k;
     ll a[n];
     for(int i=0;i<n;i++)cin>>a[i];
     int ct[n][60];
     memset(ct,0,sizeof(ct));
     for(int i=0;i<n;i++){
          ll t=a[i];
          for(int j=0;j<50;j++){
               ct[i][j]=t%2;
               t/=2;
          }
     }
     ll res=0LL,tmp=0LL;
     for(int j=59;j>=0;j--){
          int count1=0;
          for(int i=0;i<n;i++){if(ct[i][j]==1)count1++;}
          if(count1>=n-count1){
               res+=count1*(1LL<<j);
          }
          else{
               ll ty=(tmp+(1LL<<j));
               if(ty<=k){
                    tmp=ty;
                    res+=(n-count1)*(1LL<<j);
               }
               else{
                    res+=(count1)*(1LL<<j);
               }
          }
     }
     cout<<res;
}
int main(){
    optimizeIO();
    solve();
}
