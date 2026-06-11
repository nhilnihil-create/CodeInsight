#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  int count = 0;
  cin >> s;
  // cout << s.at(0) << endl;
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) == '1'){
        count++;
    }
  }
  cout << count << endl;

}

