#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,m;
	cin >> n >> m;
	int ans = 1;
	for(int i = 1;i * i <= m;i++){
		if(m % i == 0){
			if(i >= n){
				ans = max(m/i,ans);
			}
			if(m/i >= n){
				ans = max(ans,i);
			}
		}
	}
	cout << ans << endl;
}
