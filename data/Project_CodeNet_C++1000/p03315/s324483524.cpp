#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  string s;
  cin >> s;
  int count=0;
  for(int i=0;i<4;i++){
    if(s.at(i)=='+')
    count++;
    else
    count--;
  }
  cout << count << endl;
}

