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
  char x;
  int a[n];
  rep(i,0,n){
    cin>>x;
    if(x=='W') a[i]=-1;
    else a[i]=1;
  }
  if(n==1){
    cout<<0<<endl;
    return;
  }
  vector<int> pre(n,0),suf(n,0);
  pre[0]=(a[0]==-1 ?1:0);
  rep(i,1,n){
    pre[i]= (a[i]==-1 ?1:0)+pre[i-1];
  }

  suf[n-1]=(a[n-1]==1 ?1:0);
  rrep(i,n-2,0){
    suf[i]= (a[i]==1 ?1:0)+suf[i+1];
  }

  int ans=INT_MAX;
  rep(j,0,n){
    if(j==0) ans=min(ans,suf[j+1]);
    else if(j==n-1) ans=min(ans,pre[j-1]);
    else if(n>=3) ans=min(ans,pre[j-1]+suf[j+1]);
  }
  cout<<ans<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
