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
  vector<int> primes;
  rep(i,2,n/2+1){
    int flag=1;
    rep(j,2,i-1){
      if(i%j==0) flag=0;
    }
    if(flag)primes.pb(i);
  }
  // debug(primes);
  vector<pii> pr;
  for(auto i:primes){
    int c=0;
    rep(j,2,n+1){
      int temp=j;
      while(temp%i==0) c++,temp/=i;
    }
    pr.pb({i,c});
  }
  // rep(i,0,pr.size()){
  //   cout<<pr[i].f<<" "<<pr[i].s<<endl;
  // }
  ll c4=0,c2=0;
  rep(i,0,pr.size()){
    if(pr[i].s>=4) c4++;
    else if(pr[i].s>=2) c2++;
  }
  // cout<<c2<<c4<<endl;
  ll ans=((c4*(c4-1))/2)*c2+(c4*(c4-1)*(c4-2))/2;

  ll c24=0;c2=0;
  rep(i,0,pr.size()){
    if(pr[i].s>=24) c24++;
    else if(pr[i].s>=2) c2++;
  }
  // cout<<c24<<" "<<c2<<endl;
  ans+= (c24*c2+(c24*(c24-1)));

  ll c14=0;c4=0;
  rep(i,0,pr.size()){
    if(pr[i].s>=14) c14++;
    else if(pr[i].s>=4) c4++;
  }
  ans+= (c14*c4+(c14*(c14-1)));

  ll c74=0;
  rep(i,0,pr.size()){
    if(pr[i].s>=74) c74++;
  }
  ans+= c74;
  cout<<ans<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
