#include<bits/stdc++.h>
using namespace std;
typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



void solve(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ac=abs(a-c);
  if(ac<=d)cout << "Yes" << endl;
  else{
    int ab=abs(a-b);
    int bc=abs(b-c);
    if(ab<=d && bc <=d)cout << "Yes";
    else cout << "No" ;
    cout << endl;
  }
}

int main(){
  solve();
  return 0;
}
