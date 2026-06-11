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
   int a,b,q;cin>>a>>b>>q;
   vl s(a),t(b);
   rep(i,a)cin>>s[i];
   rep(i,b)cin>>t[i];
   s.push_back(-INFL);s.push_back(INFL);
   t.push_back(-INFL);t.push_back(INFL);
   sort(been(s));
   sort(been(t));
   ll Q[q];
   rep(i,q)cin>>Q[i]; 
   //cout<<s[0]<<endl;
   rep(_,q){
      ll x=Q[_];//cin>>x;
      int itr_s=lower_bound(been(s),x)-s.begin();
      int itr_t=lower_bound(been(t),x)-t.begin();
      ll ans =INFL;
      rep2(i,itr_s-1,itr_s+1){
          rep2(j,itr_t-1,itr_t+1){
              ll now=min(abs(s[i]-x)+abs(s[i]-t[j]),abs(t[j]-x)+abs(t[j]-s[i]));
              ans=min(ans,now);
          }
      }
      cout<<ans<<endl;
   }
}
