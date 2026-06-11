#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int h, w;
  cin >> h >> w;
  vector<vector<string>> vec(h+2, vector<string>(w+2));
  for (int i = 0; i < h+2; i++) {
    for (int j = 0; j < w+2; j++) {
      vec.at(i).at(j) = "*";
    }
  }

  string s;
  for (int i = 1; i < h+1; i++) {
    cin >> s;
    for (int j = 1; j < w+1; j++) {
      vec.at(i).at(j) = s[j-1];
    }
  }

  // 処理
  for (int i = 1; i < h+1; i++) {
    for (int j = 1; j < w+1; j++) {
      if(vec.at(i).at(j) == "#"){
        // if(vec.at(i-1).at(j) == "#" || vec.at(i).at(j-1) == "#" || vec.at(i).at(j+1) == "#" || vec.at(i+1).at(j) == "#")  break;

        if(vec.at(i-1).at(j) != "#" && vec.at(i).at(j-1) != "#" && vec.at(i).at(j+1) != "#" && vec.at(i+1).at(j) != "#"){
        cout << "No" << endl;
        return 0;
        }
      }
      // cout << vec.at(i).at(j) << " ";
    }
    // cout << endl;
  }

  cout << "Yes" << endl;

  // // 【確認用】
  // // 全体
  // for (int i = 0; i < h+2; i++) {
  //   for (int j = 0; j < w+2; j++) {
  //     cout << vec.at(i).at(j) << " ";
  //   }
  //   cout << endl;
  // }

  // cout << " " << endl;

  // // 該当のみ
  // for (int i = 1; i < h+1; i++) {
  //   for (int j = 1; j < w+1; j++) {
  //     cout << vec.at(i).at(j) << "";
  //   }
  //   cout << endl;
  // }

  return 0;
}