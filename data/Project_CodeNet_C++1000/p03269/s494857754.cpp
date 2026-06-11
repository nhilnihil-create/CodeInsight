#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <list>
#include <math.h>
#include <string.h>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define INF (1LL<<60)
#define int long long
#define ll long long
#define mod 1000000007


struct edge{
	int from, to, length;
};

signed main(){

	int L;
	cin >> L;
	vector<int> v;
	vector<edge> e;
	bitset<64> bit(L);

	v.push_back(0);
//	v.push_back(1);
//	e.push_back(edge{ 0, 1, 1 });
//	e.push_back(edge{ 0, 1, 0 });

	int sum = 1;
	int i;
	for (i = 63; i >= 0; i--){
		if (bit[i] == 1) break;
	}
	i--;
	for (; i >= 0; i--){
		if (bit[i] == 0){
			v.push_back(v.size());
			e.push_back(edge{ v.size() - 2, v.size() - 1, sum });
			e.push_back(edge{v.size() - 2, v.size() - 1, 0});
			sum *= 2;
		}
		else{
			v.push_back(v.size());
			e.push_back(edge{ v.size() - 2, v.size() - 1, sum });
			e.push_back(edge{ v.size() - 2, v.size() - 1, 0 });
			e.push_back(edge{ 0, v.size() - 1, sum*2 });
			sum=sum*2+1;
		}
	}

	cout << v.size() << " " << e.size() << endl;
	for (int i = 0; i < e.size(); i++)
		cout << e[i].from+1 << " " << e[i].to+1 << " " << e[i].length << endl;

	

	return 0;
}
