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
vector<int> h(101);
int solve1(int st,int en,int curr){
  if(st>en) return 0;
  int idx=min_element(h.begin()+st,h.begin()+en+1)-h.begin();
  vector<int> v;
  rep(i,st,en+1) if(h[i]==h[idx]) v.pb(i);
  int ans=solve1(st,v[0]-1,h[idx])+h[idx]-curr;
  rep(i,1,v.size()) ans+= solve1(v[i-1]+1,v[i]-1,h[idx]);
  ans+= solve1(v[v.size()-1]+1,en,h[idx]);
  return ans;
}
void  solve(){
  int n;
  cin>>n;
  rep(i,0,n) cin>>h[i];
  int idx=min_element(h.begin(),h.begin()+n)-h.begin();
  vector<int> v;
  rep(i,0,n) if(h[i]==h[idx]) v.pb(i);
  int ans=solve1(0,v[0]-1,h[idx])+h[idx];
  rep(i,1,v.size()) ans+= solve1(v[i-1]+1,v[i]-1,h[idx]);
  ans+= solve1(v[v.size()-1]+1,n-1,h[idx]);
  cout<<ans<<endl;
}
int main(){

    optimizeIO();
    // tc
    { solve();
    }
}

//
// int main(){
//
//   int N, i, j, cnt = 0; cin >> N;
//   vector<int> h(N);
//   for(i=0; i<N; i++) cin >> h[i];
//
//   while(true){
//
//     j = 0;
//     while(h[j] == 0) j++;
//
//     for(i = j; i < N; i++){
//
//       if(h[i] == 0){
//         cnt++;
//         break;
//       }
//       h[i]--;
//       if(i == N - 1) cnt++;
//     }
//
//     bool flag = true;
//     for(i = 0; i < N; i++){
//       if(h[i] != 0) flag = false;
//     }
//     if(flag){
//       cout << cnt << endl;
//       return 0;
//     }
//   }
//   return -1;
// }
