#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  set<string> st;
  char pre = '0';
  rep(i,n){
    string s;
    cin >> s;
    if(st.find(s)!=st.end()){
      cout << "No" << endl; return 0;
    }
    st.insert(s);
    if(i!=0 && pre!=s[0]){
      cout << "No" << endl; return 0;
    } else {
      pre = s.back();
    }
  }
  cout << "Yes" << endl;
  return 0;
}