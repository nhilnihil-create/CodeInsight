#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const ll inf=1e9;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  ll k,a,b;
  cin >> k >> a >> b;
  ll now = 1;
  if(b<=a+2 || k<a-1)now+=k;
  else{
    now = a;
    k -= a-1;
    now += (b-a)*(k/2);
    now += k%2;
  }
  cout << now << endl;
  return 0;
}
