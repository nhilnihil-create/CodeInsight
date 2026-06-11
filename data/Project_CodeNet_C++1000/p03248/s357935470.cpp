#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	string s;
	cin >> s;
	int n = s.length();

	for(int i = 0; i < n / 2; i++){
		if(s[i] != s[n - i - 2]){
			cout << -1 << endl;
			return 0;
		}
	}
	if(s[n - 1] == '1' || s[0] == '0'){
		cout << -1 << endl;
		return 0;
	}

	// ここまでくると、
	// - サイズnの連結成分はない
	// - サイズ1とサイズn - 1の連結成分がある
	// - サイズiとn - iの連結成分が両方ある(or ない)
	// となる
	int now = 1;
	for(int i = 1; i < s.length(); i++){
		if(s[i] == '0') continue;
		// サイズiの部分木の親ノードはi
		while(now < i + 1){
			cout << now << " " << i + 1 << endl;
			now++;
		}
	}
	while(now < n){
		cout << now << " " << n << endl;
		now++;
	}
}