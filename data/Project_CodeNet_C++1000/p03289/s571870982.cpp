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

using namespace std;
typedef pair<llint, llint> P;

string s;

bool check(char c)
{
	return c >= 'a' && c <= 'z';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	if(s[0] != 'A' || !check(s[1]) || !check(s.back())){
		cout << "WA" << endl;
		return 0;
	}
	bool flag = false;
	for(int i = 2; i < (int)s.size()-1; i++){
		if(s[i] == 'C'){
			if(flag){
				cout << "WA" << endl;
				return 0;
			}
			flag = true;
		}
		else{
			if(!check(s[i])){
				cout << "WA" << endl;
				return 0;
			}
		}
	}
	if(!flag) cout << "WA" << endl;
	else cout << "AC" << endl;
	
	return 0;
}