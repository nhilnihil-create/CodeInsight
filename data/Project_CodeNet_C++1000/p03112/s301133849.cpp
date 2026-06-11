#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
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
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
void  solve(){
  ll a,b,q,x,y;
  cin>>a>>b>>q;
  vector<ll> s,t;
  map<ll,ll> m;
  rep(i,0,a) {cin>>y; if(m.find(y)==m.end()) s.pb(y),m[y]=1;}
  m.clear();
  rep(i,0,b) {cin>>y; if(m.find(y)==m.end())t.pb(y),m[y]=1;}

  sort(all(s));
  sort(all(t));

  rep(i,0,q){
    cin>>x;
    ll ans=INF;
    ll si,tj,tj1,idx= lower_bound(all(t),x)-t.begin();

    if(idx==t.size()) tj1=INF;
    else tj1=t[idx];
    if(idx==0) tj=-INF;
    else tj=t[idx-1];
    // cout<<tj<<" "<<tj1<<endl;

    ll idx1=lower_bound(all(s),x)-s.begin(),idx2=lower_bound(all(s),x)-s.begin();
    if(idx1==s.size()) si=s[idx1-1];
    else si=s[idx1];

    if(si>=tj1) ans=min(ans,si-x);
    else if(x<=si) ans=min(ans,tj1-x),ans=min(ans,min(abs(x-tj),abs(x-si))+abs(si-tj));
    else if(si>=tj )ans=min(ans,min(abs(x-si),abs(x-tj1))+abs(si-tj1)),ans=min(ans,min(abs(x-tj),abs(x-si))+abs(si-tj));
    else ans=min(ans,abs(x-si));

      // cout<<si<<"...."<<ans<<endl;

    if(idx2==s.size()) si=s[idx2-1];
    else if(idx2>=1 )si=s[idx2-1];
    else si=s[idx2];

    if(si>=tj1) ans=min(ans,si-x);
    else if(x<=si) ans=min(ans,tj1-x),ans=min(ans,min(abs(x-tj),abs(x-si))+abs(si-tj));
    else if(si>=tj )ans=min(ans,min(abs(x-si),abs(x-tj1))+abs(si-tj1)),ans=min(ans,min(abs(x-tj),abs(x-si))+abs(si-tj));
    else ans=min(ans,abs(x-si));


    // cout<<si<<"...."<<ans<<endl;
    cout<<ans<<endl;
  }
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
