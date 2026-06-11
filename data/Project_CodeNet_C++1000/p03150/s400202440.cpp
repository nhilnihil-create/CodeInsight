#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  string s;
  cin >> s;
  string ans = "NO";
  for(int i=0;i<s.size();i++){
    for(int j=0;j+i<s.size();j++){
      string t = s;
      t.erase(i,j);
      if(t=="keyence") ans = "YES";
    }
  }


  cout << ans << endl;
}