#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main() {
  string s;
  cin >> s;
  int len = s.size();
  int cnt = 0;
  
  rep(i,len){
    if(s.at(i) == '2') cnt++;
  }
  
  cout << cnt << endl;
}