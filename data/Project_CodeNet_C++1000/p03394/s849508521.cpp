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

using namespace std;

#define mod 1000000007

int getminodd(int n)
{
	int res = 3;
	while(n >= res && n % res > 0) res += 2;
	return res;
}

int main()
{
	int n;
	cin >> n;
	if(n == 3){
		cout << 2 << " " << 5 << " " << 63 << endl;
		return 0;
	}
	vector<int> res;
	for(int i = 1; i <= 15000 && i <= n - 2; i++){
		res.push_back(2 * i);
	}
	for(int i = 3; i <= 15000; i++){
		if(getminodd(i) >= 10000 && getminodd(i + 1) >= 10000)
		cout << i << " " << getminodd(i) << endl;
	}
	int minodd = min(getminodd(res.size()), getminodd(res.size() + 1));
	if((n - res.size()) % 2 == 1) res.pop_back();
	for(int i = 0; res.size() < n; i++){
		res.push_back((2 * i + 1) * minodd);
	}
	for(int i = 0; i < n; i++){
		cout << res[i];
		if(i == n - 1) cout << endl;
		else cout << " ";
	}
}