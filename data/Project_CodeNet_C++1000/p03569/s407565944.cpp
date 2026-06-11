#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  string s;
  cin >> s;
  vector<int> x;
  vector<char> y;
  int xcnt=0;
  REP(i,s.size()){
    if(s.at(i)!='x'){
      x.push_back(xcnt);
      y.push_back(s.at(i));
      xcnt=0;
    }else{
      xcnt++;
    }
  }
  x.push_back(xcnt);
  
  int flag=0;
  if(y.size()>0){
    REP(i,(y.size()-1)/2+1){
      if(y.at(i)!=y.at(y.size()-1-i)){
        flag=1;
      }
    }
  }else{
    flag=0;
  }

  if(flag==1){
    cout << -1 << endl;
  }else{
    int ans = 0;
    REP(i,(x.size()-1)/2+1){
      ans+=abs(x.at(i)-x.at(x.size()-1-i));
    }
    cout << ans << endl;
  }
}