#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  vector<int> num(4,0);
  for(int i = 0;i < 3;i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    num.at(a)++; num.at(b)++;
  }

  for(int i = 0;i < 4;i++) {
    if(num.at(i) == 3) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}

