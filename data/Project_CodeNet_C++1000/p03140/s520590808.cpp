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

int n;

int main() {
  cin >> n;
  string a, b, c;
  cin >> a>> b >> c;
  int cnt = 0;
  for(int i=0; i<n; i++){
    if(a[i] == b[i] && b[i] == c[i]) continue;
    if(a[i] != b[i] && b[i] != c[i] && a[i] != c[i]) {
      cnt += 2;
    } else{
      cnt += 1;
    }
  }
  cout << cnt << endl;

  return 0;
}


//EOF
