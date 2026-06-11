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
  int n;

  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  map<int,int> m1,m2;
  for(int i=0;i<n;i+=2) m1[a[i]]++,m2[a[i+1]]++;
  int fi=(*m1.begin()).f,se=(*m2.begin()).f;
  vector<pii> v1,v2;
  for(auto i:m1){
    v1.pb({i.s,i.f});
  }
  for(auto i:m2){
    v2.pb({i.s,i.f});
  }
  sort(all(v1),greater<pii>());
  sort(all(v2),greater<pii>());
  if(v1[0].s!=v2[0].s){
    cout<<(n-v1[0].f-v2[0].f)<<endl;
  }
  else{
    cout<<min((n-v1[1].f-v2[0].f),(n-v1[0].f-v2[1].f))<<endl;
  }
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
