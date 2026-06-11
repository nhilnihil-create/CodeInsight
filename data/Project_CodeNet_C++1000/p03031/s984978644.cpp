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
  int N,M;
  cin >> N >> M;
  int k[M];
  int s[11][11];
  int p[M];
  rep(i,M) {
	cin >> k[i];
	rep(j,k[i]) {
	  cin >> s[i][j];
	  s[i][j]--;
	}
  }
  rep(i,M) cin >> p[i];

  
  // rep(i,M) {
  // 	rep(j,k[i]) {
  // 	  cout << s[i][j];
  // 	}
  // 	cout << endl;
  // }

  

  //make bit pattern
  int ans = 0;
  for(int bit=0; bit < (1 << N); bit++) {
	vector<bool> isturn(10,false);

	rep(i,N) {
	  if((1<<i) & bit) {
		isturn[i] = true;
	  }
	}
	
	//	for(auto itr : isturn) cout << itr;
	//	cout << endl;


	int tmp = 0;
	rep(i,M) {
	  int cnt = 0;
	  rep(j,k[i]) {
		if(isturn[s[i][j]]) cnt++;
	  }
	  if(cnt%2 == p[i]) tmp++;
	}
	if(tmp == M) ans++;
  }

  cout << ans << endl;


  return 0;
}

