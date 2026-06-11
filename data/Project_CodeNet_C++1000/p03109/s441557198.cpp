#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

int main(){
  int y,m,d;
  char a,b;
  cin>>y>>a>>m>>b>>d;
  
  if(y<2019) cout<<"Heisei"<<endl;
  else if(y>2019) cout<<"TBD"<<endl;
  else if(m<=4) cout<<"Heisei"<<endl;
  else cout<<"TBD"<<endl;

  return 0;
}