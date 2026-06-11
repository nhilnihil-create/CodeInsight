#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
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
  int n,m,y,p;
  cin>>n>>m;
  vector<vector<pii>> v(n,vector<pii>());
  rep(i,0,m){
    cin>>p>>y;
    v[p-1].pb({y,i});
  }
  string ans[m];
  rep(i,0,n) sort(all(v[i]));
  rep(i,0,n){
    int idx=i+1;
    string s=to_string(idx);
    while(s.length()!=6) s="0"+s;
    // cout<<s<<endl;
    // cout<<v[i].size()<<endl;
    rep(j,0,v[i].size()){
      int idx1=j+1;
      // cout<<idx1<<endl;
      string h=to_string(idx1);
      while(h.length()!=6) h="0"+h;
      // cout<<h<<endl;
      ans[v[i][j].s]=s+h;
    }
  }
  rep(i,0,m) cout<<ans[i]<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
