#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;


llint L;
vector<E> vec;

int main(void)
{
	cin >> L;
	llint n = 20;
	
	for(int i = 1; i < n-1; i++){
		vec.push_back(E(P(n-i, n-i+1), 1<<(i-1)));
		vec.push_back(E(P(n-i, n-i+1), 0));
	}
	
	llint sum = 0;
	if(L & (1<<(n-1))){
		vec.push_back(E(P(1, 2), 1<<(n-2)));
		vec.push_back(E(P(1, 2), 0));
		sum += 1<<(n-1);
	}
	for(int i = n-2; i >= 0; i--){
		if(L & (1<<i)){
			vec.push_back(E(P(1, n-i), sum));
			sum += 1<<i;
		}
	}
	
	cout << n << " " << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first.first << " " << vec[i].first.second << " " << vec[i].second << endl;
	}
	
	return 0;
}
