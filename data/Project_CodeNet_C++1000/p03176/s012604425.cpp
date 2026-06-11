#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define srt(a) sort(a.begin(),a.end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define endl '\n'
#define mod 1000000007
#define INF64 1e18

void solve(){
  int n ;cin>>n;
  vi h(n),a(n);
  for(int i=0;i<n;i++)
    cin>>h[i];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int ans=0;
  map<int,int> dp;
  dp.insert({0,0});
  for(int i=0;i<n;i++){
    auto it=dp.lb(h[i]);
    it--;
    int x=it->se+a[i];
    it++;
    vi b;
    while(it!=dp.end()&&x>=it->se){
      b.pb(it->fi);
      it++;
    }
    for(int j:b)
      dp.erase(j);
    dp.insert({h[i],x});
    ans=max(ans,x);
  }
  cout<<ans;
}

int32_t main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int T=1;
  //cin>>T;
  for(int TT=1;TT<=T;TT++){
    solve();
  }
}