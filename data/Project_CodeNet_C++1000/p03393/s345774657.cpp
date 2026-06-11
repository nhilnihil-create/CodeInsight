#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  string s; cin >> s;
  string txt = "abcdefghijklmnopqrstuvwxyz";
  if(s.size() < 26){
    vi word(26);
    rep(i,s.size()) word[s[i]-'a']++;
    rep(i,26){
      if(word[i] == 0){
        s += txt[i];
        break;
      }
    }
    cout << s;
    return 0;
  }else{
    for(int i = 25; 0 <= i; i--){
      if(s[i] < s[i+1]){
        char mn = s[i+1];
        for(int j = i+1; j < 26; j++){
          if(s[j] > s[i]) chmin(mn,s[j]);
        }
        cout << s.substr(0,i)+mn;
        return 0;
      }
    }
  }
  cout << -1;
  cout << "\n";
  return 0;
}
