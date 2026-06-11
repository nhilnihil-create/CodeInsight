#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 5e5 + 10;

void hi(int a){
  int temp = a;
  int cnt = 0;
  while(temp){temp/=10;cnt++;}
  cnt = 6-cnt;
  for(int i = 0;i<cnt;i++){
    cout <<0;
  }
}

void solve(){
   int n,m;cin >> n >> m;
   vector< vector<int> >p(n+10);
   vector<int>ans1(m+5);
   map<int,int>mapp;
   vector<int>c(m+5);
   for(int i = 0;i<m;i++){
    int a,b;cin >> a >> b;
    p[a].push_back(b);
    ans1[i] = a;
    c[i] = b;
}
for(int i = 1;i<=n;i++){
    sort(p[i].begin(),p[i].end());
    for(int j = 0;j<p[i].size();j++){
        mapp[p[i][j]] = j+1;
    }
}
for(int i = 0;i<m;i++){
    hi(ans1[i]);cout << ans1[i];
    hi(mapp[c[i]]);cout << mapp[c[i]];
    cout <<endl;
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}