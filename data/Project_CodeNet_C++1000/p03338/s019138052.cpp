#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)
bool key1[26], key2[26];

void kazu(string s, int a){
  int ans = 0, n = s.length();
  if(a==0)REP(i,0,26)key1[i] = false;
  else REP(i,0,26)key2[i] = false;
  REP(i,0,n){
    int c = s[i] - 'a';
    if(a==0){if(key1[c])continue;}
    else {if(key2[c])continue;}
    if(a==0)key1[c] = true;
    else key2[c] = true;
    ans++;
  }
}

int main()
{
  int ans = 0, n;
  string s;
  cin >> n;
  cin >> s;
  REP(i,1,n){
    int cnt = 0;
    string h1 = s.substr(0,i);
    string h2 = s.substr(i,n);
    kazu(h1, 0);
    kazu(h2, 1);
    REP(j,0,26){
      if(!(key1[j] && key2[j]))continue;
      cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}