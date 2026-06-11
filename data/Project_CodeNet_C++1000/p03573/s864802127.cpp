#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  cout << (A^B^C) << endl;
  return 0;
}
