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
  ll sum=0,sum1=0,sum2=0,sum3=0;
  rep(i,0,n){
    cin>>a[i];
    a[i]=(a[i]-i-1);
  }
  sort(a,a+n);
  if(n%2) sum=a[n/2];
  else sum= (a[n/2]+a[n/2-1])/2;
  rep(i,0,n) sum1+= abs(a[i]-sum);
  sum-=1;
  rep(i,0,n) sum2+= abs(a[i]-sum);
  sum+=2;
  rep(i,0,n) sum3+= abs(a[i]-sum);
  cout<<min(sum3,min(sum1,sum2))<<endl;
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
