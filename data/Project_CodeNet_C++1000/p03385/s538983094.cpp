#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int count(string t,char c){
  int num=0;
  
  rep(i,t.size())
    if(t[i]==c) num++;

  return num;
}

int main(void){
  string s; cin >> s;
  int a,b,c;
  a = count(s,'a');
  b = count(s,'b');
  c = count(s,'c');

  bool ok = true;
  if(a!=1 || b!=1 || c!=1) ok = false;

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
