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
const int INF=1e9;
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
vector<int> v(8);
int A,B,C;
int solve(int cur,int a,int b,int c,int n){
  if(cur==n){
    if(min(min(a,b),c)>0)
    // -30 is for becuase itital assignement is cost 0 but here intital assignement cost is 10 for each
    return abs(a-A)+abs(b-B)+abs(c-C)-30;
    else return INF;
  }
  int x=solve(cur+1,a,b,c,n);
  int y=solve(cur+1,a+v[cur],b,c,n)+10;
  int z=solve(cur+1,a,b+v[cur],c,n)+10;
  int w=solve(cur+1,a,b,c+v[cur],n)+10;
  return min(min(min(x,y),z),w);
}
void  solve(){
  int n;
  cin>>n>>A>>B>>C;
  rep(i,0,n) cin>>v[i];
  cout<<solve(0,0,0,0,n)<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
