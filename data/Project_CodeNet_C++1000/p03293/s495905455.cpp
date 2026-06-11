#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  string s,t;
  cin>>s>>t;
  int sz=s.size();

  rep(i,sz){
    if(s==t){
      cout<<"Yes\n";
      return 0;
    }

    char c=s[sz-1];
    s.pop_back();
    s=c+s;
  }

  if(s==t){
      cout<<"Yes\n";
      return 0;
  }
  cout<<"No\n";


  return 0;
}
