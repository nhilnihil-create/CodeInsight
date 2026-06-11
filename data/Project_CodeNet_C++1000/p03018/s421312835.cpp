#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin >> s;
  vector<string> a;
  int begin = 0;
  for(int i = 0;i < s.size();i++){
    if(s[i] == 'A'){}
    else if(s[i] == 'B' && s[i + 1] == 'C')i++;
    else{
      a.push_back(s.substr(begin,i - begin));
      begin = i + 1;
    }
  }
  //cout << 1 << endl;
  //cout << begin << endl;
  if(s.size() - 1 > begin)a.push_back(s.substr(begin,s.size() - begin + 1));
  ll res = 0;
  //cout << a[0].size() << endl;
  //cout << 2 << endl;
  //cout << a[1] << endl;
  for(int i = 0;i < a.size();i++){
    ll count = 0;
    string sub;
    sub = a[i];
    //cout << "sub " << sub << endl;
    for(int j = sub.size() - 1;j >= 0;j--){
      //cout << sub[j] << endl;
      if(sub[j] == 'C'){
        count++;
        j--;
      }
      if(sub[j] == 'A')res += count;
    }
  }
  cout << res << endl;
  return 0;
}