#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  vector<int> num(10);
  for(int i = 0;i < 4;i++) {
    int n;
    cin >> n;
    num.at(n)++;
  }

  if(num.at(1)&&num.at(9)&&num.at(7)&&num.at(4)) cout << "YES" << endl;
  else cout << "NO" << endl;

}

