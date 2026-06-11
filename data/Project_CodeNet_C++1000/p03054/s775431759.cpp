#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n = 0):n(n),d(n+1){}
  void add(int i,T x=1){
    for(i++;i<=n;i += i&-i){
      d[i] += x;
    }
  }
  T sum(int i){
    T x = 0;
    for(i++;i>0;i -= i&-i){
      x += d[i];
    }
    return x;
  }
};
 
int main(){
  int h,w,n;cin >> h >> w >> n;
  int sr,sc; cin >> sr >> sc;
  string s,t;cin >> s >> t;
  string right = "",left = "",up = "",down = "";
  rep(i,n){
    char ch = s[i];
    if(ch == 'U') up.push_back(ch);
    else if(ch == 'D') down.push_back(ch);
    else if(ch == 'R') right.push_back(ch);
    else left.push_back(ch);
    ch = t[i];
    if(ch == 'U') down.push_back(ch);
    else if(ch == 'D') up.push_back(ch);
    else if(ch == 'R') left.push_back(ch);
    else right.push_back(ch);
  }
  int cnt = sr;
  rep(i,up.size()){
    if(up[i]=='U') cnt--;
    else {
      cnt++;
      if(cnt > h) cnt = h;
    }
    if(cnt <= 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cnt = sr;
  rep(i,down.size()){
    if(down[i]=='D') cnt++;
    else {
      cnt--;
      if(cnt <= 0) cnt = 1;
    }
    if(cnt > h){
      cout << "NO" << endl;
      return 0;
    }
  }
  cnt = sc;
  rep(i,right.size()){
    if(right[i]=='R') cnt++;
    else {
      cnt--;
      if(cnt <= 0) cnt = 1;
    }
    if(cnt > w){
      cout << "NO" << endl;
      return 0;
    }
  }
  cnt = sc;
  //cout << left << endl;
  rep(i,left.size()){
    if(left[i]=='L') cnt--;
    else {
      cnt++;
      if(cnt > w) cnt = w;
    }
    if(cnt <= 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  
}