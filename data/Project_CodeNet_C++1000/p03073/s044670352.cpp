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
  string s;
  cin>>s;
  int n=s.length();
  int a[n],b[n];
  rep(i,0,n){
    a[i]=(i+1)%2;
  }
  rep(i,0,n){
    b[i]=i%2;
  }
  int mx1=0,mx2=0;
  rep(i,0,n){
    mx1 += abs(a[i]-(s[i]-'0'));
    mx2 += abs(b[i]-(s[i]-'0'));
  }
  cout<<min(mx1,mx2)<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
