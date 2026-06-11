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


int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}



int diviser(int n) {
  int ret = 0;
  for(int i=1; i<=n; i++) {
	if(n % i == 0) ret++;
  }
  return ret;
}


int main(){
  int N;
  int ans = 0;
  cin >> N;
  for(int i=1; i <=N; i++) {
	if(i % 2 == 1) {
	  int num = diviser(i);
	  if(num == 8) ans++;
	}
  }
  cout << ans << endl;
  return 0;
}

