#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
  string s;
  cin >> s;
  int ans = 0;
  int tmp = 0;
  rep(i,int(s.size())) {
	if(s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C') {
	  tmp++;
	}
	else {
	  ans = max(tmp,ans);
	  tmp = 0;
	}
	if(i == int(s.size())-1) {
	  ans = max(tmp,ans);
	}
  }
  cout << ans << endl;
  return 0;
}
