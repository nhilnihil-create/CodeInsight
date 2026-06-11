#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<random>
using namespace std;
 
int main() {
 
  string s; cin >> s;
 
  int a[3] = {0,0,0};
 
  for(int i=0; i<s.size(); i++){
    a[ s[i]-'a' ]++;
  }
  if( max({a[0],a[1],a[2]}) - min({a[0],a[1],a[2]}) <= 1 ) cout << "YES" << endl;
  else cout << "NO" << endl;
 
  return 0;
}
 
// EOF