#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
   ll n,k;
   cin>>n>>k;
   ll v[n];
   rep(i,n)cin>>v[i];
   ll ans = -INFL;
   rep(i,n+1){
       rep2(j,i,n+1){
           vl s;
           int le = k-i;
           //cout<<le<<endl;
           if(le<0)continue;
           rep(a,i){
               s.push_back(v[a]);
           }
           for(int a = n-1;a>=j&&le>=0;a--,le--){
               s.push_back(v[a]);
           }
           if(le<0)continue;
           sort(been(s));
           ll sum =0;
           rep(a,le){
               if(a>=s.size())break;
               if(s[a]>=0)break;
               sum-=s[a];
           }
           rep(a,s.size()){
               sum+=s[a];
           }
           ans=max(ans,sum);
       }
   }
   cout<<ans<<endl;
}