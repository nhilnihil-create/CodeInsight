#include<iostream>
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
#include<list>
#include<set>
#include<cstring>
using namespace std;

int main() {

  vector<int> c = {0, 0, 0, 0};
  int a, b;
  for(int i=0; i<3; i++){
    cin >> a >> b;
    c[a-1]++;
    c[b-1]++;
  }
  sort(c.begin(), c.end());
  if(c[3] == 3 || c[0] == 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;

  return 0;
}


//EOF
