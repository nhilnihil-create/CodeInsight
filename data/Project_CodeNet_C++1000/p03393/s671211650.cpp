#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009

int main(){
  string s;
  cin >> s;
  vbool eng(26);
  rep(i,s.size()){
    eng[s[i]-'a'] = true;
  }
  int key = 0;
  bool flag = false;
  rep(i,26){
    if(eng[i] == false){
      key = i;
      flag = true;
      break;
    }
  }
  if(flag) cout << s << (char)('a' + key) << endl;
  else if(s == "zyxwvutsrqponmlkjihgfedcba") cout << -1 << endl;
  else{
    int num = INF;
    int numnum = -1;
    for(int i = 25;i >= 0;i--){
      if(s[i] - 'a' > numnum){
        numnum = s[i] - 'a';
      }
      else{
        rep(j,i){
          cout << s[j];
        }
        int ansmin = INF;
        for(int j = i;j < 26;j++){
          if((int)s[i] < (int)s[j])
            ansmin = min(ansmin,(int)s[j]);
        }
        cout << (char)(ansmin) << endl;
        break;
      }
    }
  }
}
