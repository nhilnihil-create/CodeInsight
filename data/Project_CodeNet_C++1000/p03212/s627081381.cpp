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
ll fact[15];
ll solve1(ll a, ll b, ll c,ll n){
  // cout<<n<<endl;
  if(a+b+c==n){
    // cout<<n<<" "<<a<<" "<<b<<" "<<c<<endl;
    // cout<<fact[a]<<endl;
    return fact[n]/(fact[a]*fact[b]*fact[c]);
  }
  return solve1(a+1,b,c,n)+solve1(a,1+b,c,n)+solve1(a,b,c+1,n);
}
ll solve2(int n){
  ll ans=0;
  rep(i,3,n+1){
    ans+=solve1(1,1,1,i);
  }
  return ans;
}
void  solve(){
  // string s;
  // cin>>s;
  // fact[0]=1;
  // rep(i,1,13) fact[i]=i*fact[i-1];
  // int n=s.length();
  // ll ans=solve2(n-1);
  // ll mult=1;
  // // rep(i,1,n){
  // //   ll c=0;
  // //   if(s[i]>='3')  c++;
  // //   if(s[i]>='5')  c++;
  // //   if(s[i]>='7')  c++;
  // //   mult*=c;
  // // }
  // if(s[0]>'7'){
  //   ans+= 3*solve2(n-1);
  // }
  // else if(s[0]=='7' || s[0]>'5'){
  //   ans+=2*solve2(n-1);
  // }
  // else if(s[0]=='5' || s[0]>'3'){
  //   ans+= solve2(n-1);
  // }
  // if(s[0]<'3') mult=0;
  // else{
  //
  //   int x=stoi(s);
  //   if(s[0]>'7')
  //   rrep(i,x,)
  // }
  // ans+=mult;
  // cout<<ans<<endl;
  int n;
  cin>>n;
  int ans = 0;
  function<void(string, bool, bool, bool)> rec = [&](string s, bool three,
                                                     bool five, bool seven) {
    if (s.size() >= 10) return;
    if (three && five && seven && stoll(s) <= n) ++ans;
    rec(s + '3', true, five, seven);
    rec(s + '5', three, true, seven);
    rec(s + '7', three, five, true);
  };
  rec("", false, false, false);
  cout<<ans<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
