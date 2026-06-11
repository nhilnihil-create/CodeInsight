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
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

int main() {
  int n, h, w; cin >> n >> h >> w;
  cout << (n-h+1) * (n-w+1) << endl;

  return 0;
}



///
