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
  string s;
  cin >> s;
  bool can = true;
  if(s[0] == '0')can = false;
  if(s[s.size() - 1] == '1')can = false;
  //cout << s[s.size() - 1] << endl;
  for(int i = 1;i < s.size() / 2;i++){
    if(s[i] != s[s.size() - i - 2])can = false;
  }
  if(!can){
    cout << -1 << endl;
  }
  else{
    ll mae = 0;
    for(int i = s.size() - 1;i >= 0;i--){
      if(s[i] == '1'){
        mae = i;
        i = -1;
        //cout << i << endl;
      }
    }
    vector<ll> res(s.size());
    for(int i = s.size() - 1;i >= 0;i--){
      //cout << s[i] << " ";
      /*if(s[i] == '0')cout << 1 << " " << i + 1 << endl;
      else{
        cout << mae + 1 << " " << i + 1 << endl;
        mae = i;
      }*/
      //cout << mae + 1 << " " << i + 1 << endl;
      res[i] = mae;
      if(s[i] == '1')mae = i;
    }
    for(int i = 0;i < s.size();i++){
      if(i == res[i])continue;
      cout << i + 1 << " " << res[i] + 1 << endl;
    }
  }
}