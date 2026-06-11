#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
string s;
cin >> s;
int cnt = 0;
rep(i,s.size()-1){
  if(s.at(i) == s.at(i+1)){
    if(s.at(i) == '1') s.at(i+1) = '0';
    else s.at(i+1) = '1';
    cnt++;
  }
}

cout << cnt << endl;

}
