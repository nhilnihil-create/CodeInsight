#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

ll fanc(string now){
  ll ret = 0;
  vector<int> tr;
  rep(i, now.size()){
    if(now.at(i) == 'A'){
      tr.push_back(1);
    }else{
      tr.push_back(0);
      i++;
    }
  }
  int con = 0;
  rep(i, tr.size()){
    if(tr.at(i) == 0){
      ret += i - con;
      con++;
    }
  }

  return ret;
}

int main(){
  string s;
  cin >> s;
  string now;
  ll ans = 0;
  rep(i, s.size()){
    bool flag = false;
    if(s[i] == 'A') now.push_back('A');
    else if(s[i] == 'B'){
      if(i+1 < s.size() && s.at(i+1) == 'C'){
        now += "BC";
        i++;
      }else{
        flag = true;
      }
    }else{
      flag = true;
    }
    if(flag == true){
      ans += fanc(now);
      now = "";
    }
  }
  ans += fanc(now);
  cout << ans << endl;
  return 0;
}