#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

pll qr(ll a,ll b){
  if(a>=0) return pll(a/b,a%b);
  if(a%b==0) return pll(a/b,0);
  if(b>0) return pll(a/b-1,a-(a/b-1)*b);
  else return pll(a/b+1,a-(a/b+1)*b);
}

int main(){
  itn n; cin >> n;
  string s;
  while(1){
    ll q,r;
    tie(q,r)=qr(n,(-2));
    //cout << q << " " << r << endl;
    s=to_string(r)+s;
    n=q;
    if(n==0) break;
  }
  cout << s << endl;
}