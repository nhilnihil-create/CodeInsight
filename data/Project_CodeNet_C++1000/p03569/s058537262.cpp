#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

bool check(vector<char> c){
  bool res = 1;
  rep(i,c.size()/2){
    //cout << c[i] << " " << c[c.size()-i-1] << endl;
    if(c[i]!=c[c.size()-i-1])res=0;
  }
  return res;
}

int main(){
  string s;
  cin >> s;
  vector<char> c;
  rep(i,s.size())if(s[i]!='x')c.push_back(s[i]);
  //cout << check(c) << endl;
  if(check(c)==0)cout << -1 << endl;
  else{
    int left = 0;
    int right = s.size()-1;
    int ans = 0;
    while(left<right){
      //cout << left << ' ' << right << endl;
      if(s[left]==s[right])left++,right--;
      else if(s[left]=='x')ans++,left++;
      else ans++,right--;
    }
    cout << ans << endl;
  }
  return 0;
}
