#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
struct UF
{
  vector<int> par;
  vector<int> sz;
  vector<int> rank;
  UF(int n):par(n),sz(n),rank(n){
    for(int i = 0; i < n; i++){
      par[i] = i;sz[i] = 1;rank[i] = 0;
    }
  }
  int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }
  void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if(rank[x] < rank[y]){
      par[x] = y;
      sz[y] += sz[x];
    }
    else{
      par[y] = x;
      sz[x] += sz[y];
      if(rank[x] == rank[y])rank[x]++;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int n){return sz[find(n)];}
};

bool isdig(char c){
  return '0' <= c && c <= '9';
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;cin>>s;
  ll a;cin>>a;
  for(int i=0;i<s.size();i+=a){
    cout<<s[i];
  }
  cout<<endl;
  return 0;
}

