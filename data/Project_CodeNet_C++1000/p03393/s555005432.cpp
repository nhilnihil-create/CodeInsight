#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

string s;

int main(){
  cin >> s;
  int n = s.size();
  if(n == 26 && s == "zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 << endl;
  }else if(n == 26){
    string t = s;
    next_permutation(s.begin(), s.end());
    rep(i, n){
      if(s.at(i) != t.at(i)){
        s = s.substr(0, i + 1);
        break;
      }
    }
    cout << s << endl;
  }else{
    int memo[30];
    rep(i, 30) memo[i] = 0;
    rep(i, n){
      memo[s.at(i) - 'a']++;
    }
    int c;
    rep(i, 30){
      if(memo[i] == 0){
        c = 'a' + i;
        break;
      }
    }
    cout << s << (char)c << endl;
  }
}
