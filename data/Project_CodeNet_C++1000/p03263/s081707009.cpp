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
  int h,w;
  cin>>h>>w;
  vector<vector<int>> v(h,vector<int>(w));
  rep(i,0,h) rep(j,0,w) cin>>v[i][j];
  int c=0;
  vector<pii> ans;
  while(c!=h){
    if(c%2==0){
      rep(i,1,w){
        if(v[c][i-1]%2==1){
          v[c][i]++;
          ans.pb({c+1,i});
          ans.pb({c+1,i+1});
        }
      }
      c++;
      if(c<h){
        if(v[c-1][w-1]%2==1){
          v[c][w-1]++;
          ans.pb({c,w});
          ans.pb({c+1,w});
        }
      }
    }
    else{
      rrep(i,w-2,0){
        if(v[c][i+1]%2==1){
          v[c][i]++;
          ans.pb({c+1,i+2});
          ans.pb({c+1,i+1});
        }
      }
      c++;
      if(c<h){
        if(v[c-1][0]%2==1){
          v[c][0]++;
          ans.pb({c,1});
          ans.pb({c+1,1});
        }
      }
    }
  }
  cout<<ans.size()/2<<endl;
  for(int i=0;i<ans.size();i+=2){
    cout<<ans[i].f<<" "<<ans[i].s<<" "<<ans[i+1].f<<" "<<ans[i+1].s<<endl;
  }
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
