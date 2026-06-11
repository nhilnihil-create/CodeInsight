#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  map<int, int> mp;
  while(n--){
    int d;  cin >> d;
    mp[d] = 1;
  }

  cout << mp.size() << endl;

  return 0;
}
