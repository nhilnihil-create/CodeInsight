#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
//これがdiff300台ってマジ？怖い
int countCharType(string,string);

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  int ans = 0; //最大の文字種類和
  for(int i = 1; i < n; i++){
    string s1 = s.substr(0,i);
    string s2 = s.substr(i);
    int charType = countCharType(s1,s2);
    ans = max(ans,charType);
  }
  cout << ans << endl;
}

//XとYのどちらにも含まれている文字の種類数(bothExist)を計算
int countCharType(string s1,string s2){
  sort(s1.begin(),s1.end());
  int bothExist = 0;
  rep(i,s1.size()){
    if(i==0){
      if(s2.find(s1[i]) != -1) bothExist++;
    }else{
      if(s1[i] != s1[i-1]){ //Xのi番目とi-1番目の文字が異なる場合、
        if(s2.find(s1[i]) != -1) bothExist++; //i番目の文字がYに存在するか確認
      }
    }
  }
  return bothExist;
}
  