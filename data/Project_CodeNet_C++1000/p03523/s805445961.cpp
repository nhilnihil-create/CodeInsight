#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int li;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;

const int dx[]={0,-1,1,0},dy[]={-1,0,0,1};

int main(){

  string s;cin>>s;
  string kihbr="KIHBR";

  string t="";
  bool e=true;
  rep(i,0,s.size()){
    if(s[i]!='A')t+=s[i];
  }
  ll Anum=s.size()-t.size();
  if(Anum>4)e=false;
  if(t!=kihbr)e=false;

  if(!e){
    out("NO");
    return 0;
  }

  ll correctAcount=0;

  rep(i,0,s.size()-1){
    string k="";
    k+=s[i];
    k+=s[i+1];
    if(k=="AK")correctAcount++;
    else if(k=="HA")correctAcount++;
    else if(k=="BA")correctAcount++;
    else if(k=="RA")correctAcount++;
  }

  if(correctAcount!=Anum)e=false;

  if(e)out("YES");
  else out("NO");

  return 0;
}
