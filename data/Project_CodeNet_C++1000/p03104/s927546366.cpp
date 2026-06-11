#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
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
const long long INFL = 2e18;
const int MOD = 1000000007;
int main(){
	ll a,b;
	cin >> a >> b;

	ll b_xor;
	ll a_xor;
	if(b % 2 == 0){
	   b_xor = ((b / 2) % 2) ^ b;
	}
	else{
		b_xor = ((b + 1) / 2) % 2;
	}

	if(a == 0){
		cout << b_xor << endl;
		return 0;
	}

	if((a - 1) % 2 == 0){
		a_xor = (((a-1) / 2) % 2) ^ (a - 1);
	}
	else{
		a_xor = (a / 2) % 2;
	}
	cout << (b_xor ^ a_xor) << endl;;
}
