#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;
ll mod = 1e9+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

pair<vector<char>, vector<int>> compress(string str){
  vector<char> vect_char;
  vector<int> vect_cnt;

  int tmp_cnt = 0;
  int tmp_char;
  rep(i, sz(str)){
    if(i==0){
      tmp_cnt++;
      tmp_char = str[i];
      continue;
    }

    if(tmp_char != str[i]){
      vect_char.push_back(tmp_char);
      vect_cnt.push_back(tmp_cnt);
      tmp_char = str[i];
      tmp_cnt = 1;
    }else{
      tmp_cnt++;
    }
  }

  vect_char.push_back(tmp_char);
  vect_cnt.push_back(tmp_cnt);

  return make_pair(vect_char, vect_cnt);
}

int main(){
  string S, T;
  cin >> S >> T;

  pair<vector<char>, vector<int>> s_p = compress(S);
  pair<vector<char>, vector<int>> t_p = compress(T);

  // 数
  if(sz(s_p.second) != sz(t_p.second)){
    cout << "No" << endl;
    return 0;
  }
  rep(i, sz(s_p.second)){
    if(s_p.second[i] != t_p.second[i]){
      cout << "No" << endl;
      return 0;
    }
  }

  // 文字
  if(sz(s_p.first) != sz(t_p.first)){
    cout << "No" << endl;
    return 0;
  }

  // s_p, t_p
  map<char, char> mp;
  rep(i, sz(s_p.first)){
    if(mp.count(s_p.first[i]) != 0){
      if(mp[s_p.first[i]] != t_p.first[i]){
        cout << "No" << endl;
        return 0;
      }
    }else{
      mp[s_p.first[i]] = t_p.first[i];
    }
  }

  mp.clear();
  rep(i, sz(t_p.first)){
    if(mp.count(t_p.first[i]) != 0){
      if(mp[t_p.first[i]] != s_p.first[i]){
        cout << "No" << endl;
        return 0;
      }
    }else{
      mp[t_p.first[i]] = s_p.first[i];
    }
  }

  cout << "Yes" << endl;

  return 0;
}
