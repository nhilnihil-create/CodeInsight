//https://ykmaku.hatenablog.com/entry/2018/08/30/181652
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll MAXN = 8020;

int main()
{
  string s;
  cin >> s;
  int x,y;
  cin >> x >> y;

  vector<int> t;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'T'){
      if(cnt != 0) t.push_back(cnt);
      t.push_back(0);
      cnt = 0;
    }else{
      cnt++;
      if(i == s.size()-1) t.push_back(cnt);
    }
  }

  set<int> pos_x,pos_y;
  pos_x.insert(0);
  pos_y.insert(0);
  bool xy = true;
  for(int i = 0; i < t.size(); i++){
    set<int> pos;
    if(t[i] == 0) xy = !xy;
    else if(xy){
      for(auto itr = pos_x.begin(); itr != pos_x.end(); itr++){
        pos.insert(*itr+t[i]);
        if(i!=0) pos.insert(*itr-t[i]);
      }

      pos_x = pos;
    }else{
      for(auto itr = pos_y.begin(); itr != pos_y.end(); itr++){
        pos.insert(*itr+t[i]);
        pos.insert(*itr-t[i]);
      }
      pos_y = pos;
    }
  }

  // for(auto itr = pos_x.begin(); itr != pos_x.end(); itr++){
  //       cout << *itr << endl;
  // }

  cout << ((pos_x.find(x) != pos_x.end() && pos_y.find(y) != pos_y.end()) ? "Yes" : "No") << endl;

  return 0;
}

