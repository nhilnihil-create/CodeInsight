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
  int n, a, b; cin >> n >> a >> b;

  cout << min(a, b) << " " << max(a+b-n, 0) << endl;

  return 0;
}



//EOF
