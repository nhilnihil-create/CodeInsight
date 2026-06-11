#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  string s,t;
  cin >> s >> t;
  vector<pair<char,char>> count(s.size());
  for(int i = 0;i < s.size();i++)count[i] = make_pair(s[i],t[i]);
  sort(count.begin(),count.end());
  //for(int i = 0;i < s.size();i++)cout << count[i].first << " " << count[i].second << endl;
  bool res = true;
  for(int i = 0;i < count.size() - 1;i++){
    if(count[i].first == count[i + 1].first){
      if(count[i].second != count[i + 1].second)res = false;
    }
  }
  for(int i = 0;i < s.size();i++)count[i] = make_pair(t[i],s[i]);
  sort(count.begin(),count.end());
  //for(int i = 0;i < s.size();i++)cout << count[i].first << " " << count[i].second << endl;
  for(int i = 0;i < count.size() - 1;i++){
    if(count[i].first == count[i + 1].first){
      if(count[i].second != count[i + 1].second)res = false;
    }
  }
  if(res)cout << "Yes" << endl;
  else cout << "No" << endl;
}