#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >>s;
  int w;
  cin >>w;
  string t = " ";
  for(int i = 0; i < s.size(); i+=w){
    t += s[i];
  }
  cout << t << endl;
  return 0;
}