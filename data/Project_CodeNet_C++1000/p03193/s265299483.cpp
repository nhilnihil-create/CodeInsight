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
long long int mod = 1e9 + 7;
int main() {
  int n, h, w; cin >> n >> h >> w;
  int cnt = 0;
  for(int i=0; i<n; i++) {
    int a, b; cin >> a >> b;
    if(a >= h && b >= w) cnt++;
  }
  cout << cnt << endl;

  return 0;
}



//EOF
