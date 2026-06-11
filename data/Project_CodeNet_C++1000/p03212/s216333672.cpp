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
#include <ctime>
using namespace std;
typedef long long ll;
int main(){
  ll n = 0;
  cin >> n;
  string s;
  ll res = 0;
  s = "3";
  while(1){
    //cout << s << endl;
    if(n < stoll(s))break;
    bool ok3 = false;
    bool ok5 = false;
    bool ok7 = false;
    for(int j = 0;j < s.size();j++){
      if(s[j] == '3')ok3 = true;
      if(s[j] == '5')ok5 = true;
      if(s[j] == '7')ok7 = true;
    };
    if(ok3 && ok5 && ok7){
      //cout << s << endl;
      res++;
    }
    for(int i = s.size() - 1;i >= 0;i--){
      if(s[i] == '3'){
        s[i] = '5';
        break;
      }
      else if(s[i] == '5'){
        s[i] = '7';
        break;
      }
      else s[i] = '3';
      if(i == 0){
        s = '3' + s;
        for(int j = 0;j < s.size();j++)s[j] = '3';
        break;
      }
    }
  }
  cout << res << endl;
}