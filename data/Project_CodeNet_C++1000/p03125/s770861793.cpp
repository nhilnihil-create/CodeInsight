#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>

#define rep(i,n) for(ll i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

using Graph = vector<vector<ll>>;
//	std::cout<<std::fixed<<std::setprecision(10);


int main() {
  int A, B;
  cin >> A >> B;
  if(B%A==0) cout << A+B << endl;
  else cout << B - A << endl;

  return 0;
}
