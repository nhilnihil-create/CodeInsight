#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

bool check(string s, string t){
  int n = s.size();
  bool ok = true;
  rep(i,n){
    if (s[i]=='?' || s[i]==t[i]) continue;
    else {
      ok = false;
      break;
    }
  }

  return ok;
}

int main(){
  string s, t; cin >> s >> t;
  vector<int> d;

  int n = t.size();
  rep(i,s.size()-n+1){
    if (check(s.substr(i,n),t)) d.push_back(i);
  }


  if (d.size()==0) cout << "UNRESTORABLE" << endl;
  else {
    int idx = d[d.size()-1];
    rep(i,n) {
      s[idx+i] = t[i];
    }
    rep(i,s.size()){
      if (s[i]=='?') s[i] = 'a';
    }
    cout << s << endl;

  }



  // cout << fixed << setprecision(10);
  
  return 0;
}
