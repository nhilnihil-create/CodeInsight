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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint n, a, b;
vector<llint> vec;
vector<llint> comp;

int main(void)
{
	cin >> n >> a >> b;
	if(n < a+b-1 || n > a*b){
		cout << -1 << endl;
		return 0;
	}
	
	llint rem = n - b;
	for(int i = 1; i <= b; i++){
		llint x = min(rem, a-1);
		rem -= x;
		x++;
		for(int j = 0; j < x; j++) vec.push_back(-100000000LL*i+j);
	}
	for(int i = 0; i < vec.size(); i++) comp.push_back(vec[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 0; i < vec.size(); i++) vec[i] = lower_bound(comp.begin(), comp.end(), vec[i]) - comp.begin() + 1;
	
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	return 0;
}
