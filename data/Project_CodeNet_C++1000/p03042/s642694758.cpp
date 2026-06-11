#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  string s;
  cin>>s;
  bool mae=false,usiro=false;
  if(s[0]=='0'&&s[1]!='0' ||s[0]=='1' &&s[1]<'3') mae=true;
  else mae=false;
  if(s[2]=='0'&&s[3]!='0' ||s[2]=='1' && s[3]<'3') usiro=true;
  else usiro=false;
  if(mae&&usiro) cout<<"AMBIGUOUS"<<endl;
  else if(mae&&!usiro) cout<<"MMYY"<<endl;
  else if(!mae&&usiro) cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
}