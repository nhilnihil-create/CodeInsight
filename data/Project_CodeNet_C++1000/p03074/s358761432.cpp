#include <bits/stdc++.h>
#include <cstdint>
#define pi 3.14159
#define ll long long
// #define int ll
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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
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
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  int l=0,r=0;
  while(r<n && s[r]=='1') r++;
  int ans=0;
  while(k){
    while(r<n && s[r]=='0') r++;
    while(r<n && s[r]=='1') r++;
    k--;
  }
  ans=r-l;
  while(r<n){
    while(l<n && s[l]=='1') l++;
    while(l<n && s[l]=='0') l++;
    while(r<n && s[r]=='0') r++;
    while(r<n && s[r]=='1') r++;
    ans=max(ans,r-l);
  }
  cout<<ans<<endl;
}
int main(){
    optimizeIO();
    solve();
}
