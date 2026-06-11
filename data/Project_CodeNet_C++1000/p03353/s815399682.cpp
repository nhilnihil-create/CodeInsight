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

const int mx=200010;
const ll mod=1e9+7;

int main(){
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  vector<string> v;
  rep(i,n){
    string t="";
    t+=s[i];
    rep(j,5){
      v.push_back(t);
      if(i+j+1<n){ t+=s[i+j+1]; }
    }
  }
  
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  
  cout << v[k-1] << endl;
  return 0;
}
