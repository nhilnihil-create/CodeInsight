#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
  map<int,int> mpd,mpt;
  int n;
  cin >> n;
  int d[n];
  for(int i = 0; i < n; i++) {
    cin >> d[i];
  }
  for(int i = 0; i < n; i++) {
    mpd[d[i]]++;
  }
  int m;
  cin >> m;
  int t[m];
  for(int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for(int i = 0; i < m; i++) {
    mpt[t[i]]++;
  }
  for(int i = 0; i < m; i++) {
    if(mpt[t[i]] > mpd[t[i]]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}