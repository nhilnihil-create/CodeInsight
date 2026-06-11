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
  if(s.size() < t.size()){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  if(s.size() == 1 && t.size() == 1){
    if(s == t || s == "?")cout << t << endl;
    else cout << "UNRESTORABLE" << endl;
    return 0;
  }
  vector<string> res;
  for(int i = 0;i <= s.size() - t.size();i++){
    bool now = true;
    for(int j = 0;j < t.size();j++){
      if(s[i + j] != '?' && s[i + j] != t[j])now = false;
    }
    if(now){
      string in;
      in += s.substr(0,i);
      //cout << i << " " << in << endl;
      in += t;
      //cout << i << " " << in << endl;
      //cout<<i+t.size()+1<<" "<<s.size()-i-t.size()<<endl;
      in += s.substr(i + t.size(),s.size() - i - t.size());
      //cout << i << " " << in << endl;
      for(int k = 0;k < in.size();k++){
        if(in[k] == '?')in[k] = 'a';
      }
      res.push_back(in);
      //cout << i << " " << in << endl;
    }
    //cout << i << endl;
  }
  sort(res.begin(),res.end());
  if(res.size() == 0)cout << "UNRESTORABLE" << endl;
  else cout << res[0] << endl;
}