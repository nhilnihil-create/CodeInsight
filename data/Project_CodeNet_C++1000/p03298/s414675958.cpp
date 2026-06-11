#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<"!"<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll n;
string s;
map<pair<string,string>,ll>cnt;
ll ans=0;
void mae(string ss,string sss,ll depth){
  if(depth==n){
    reverse(ALL(ss));
    reverse(ALL(sss));
    cnt[mp(ss,sss)]++;
    return;
  }
  mae(ss+s[depth],sss,depth+1);
  mae(ss,sss+s[depth],depth+1);
}
void ushiro(string ss,string sss,ll depth){
  if(depth==2*n){
    ans+=cnt[mp(ss,sss)];
    return;
  }
  ushiro(ss+s[depth],sss,depth+1);
  ushiro(ss,sss+s[depth],depth+1);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  cin>>s;
  mae("","",0);
  ushiro("","",n);
  cout<<ans<<endl;
  return 0;
}
