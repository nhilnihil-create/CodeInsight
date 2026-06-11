#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n;
  cin >> n;
  vector<int>vec(n);
  while(true){
    int l=0,r=n;
    cout << 0 << endl;
    string s;
    cin >> s;
    if(s[0]=='V')return 0;
    else if(s[0]=='M')vec[0]=1;
    else vec[0]=0;
    
    while(true){
      int m=(r+l)/2;
      cout << m << endl;
      string t;
      cin >> t;
      if(t[0]=='V')return 0;
      else if(t[0]=='M')vec[m]=1;
      else vec[m]=0;
      
      if((m-l)%2^vec[m]==vec[l])l=m;
      else r=m;
    }
    
  }
  return 0;     
}
