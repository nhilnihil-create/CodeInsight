#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;
///vector<pair<string, int>>;

int main(){
  string s, t;
  cin >> s >> t;
  int check = 0, same = 0;
  int ls = s.length(), lt = t.length();
  rep(i, ls){
    rep(j, lt){
      int ns = s[i] - '0', nt = t[j] - '0';
      if(ns < nt) {
        check = 1;
        break;
      }
    }
    if(t.find(s[i])!= string::npos) same++;
    if(check) break;
  }
  if (ls < lt && same == ls) check = 1;
  if(check) cout << "Yes" << endl;
  else cout << "No" << endl;
}
