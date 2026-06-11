#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  int ans = 0, kind = 0; ///kindはsの文字の種類

  int num = 'a'-'0' + 26;
  int check[num];
  int basyo[n]; ///i文字目までに存在する文字の種類
  rep(i, num) check[i] = 0;
  rep(i, n) basyo[i] = 0;
  rep(i, n){
    if (check[s[i]-'0'] == 0){
      kind++;
      check[s[i]-'0'] ++;
    }
    basyo[i] = kind;

  }

  rep(i, n){
    int ari = 0;
    int ch[num];
    rep(i, num) ch[i] = 0;
    string s1 = s.substr(0, i);
    string s2 = s.substr(i);
    
    rep(j, s1.length()){
      rep(k, s2.length()){
        if (s1[j] == s2[k] && ch[s1[j]-'0']== 0){
          ari ++;
          ch[s1[j]-'0']++;

        }
      }
    }
  
    if (ari > ans) ans = ari;

  }
  cout << ans << endl;
}
