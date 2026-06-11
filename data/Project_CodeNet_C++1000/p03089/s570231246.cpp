#include <iostream>
#include <sstream>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>
#include <list>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main(void)
{
	int N; cin >> N;
	vector<int> B(N); rep(i, 0, N)cin >> B[i];

	bool judge = true;
	list<int> ans;
	rep(i, 0, N) {
		if (B[i] == 1)ans.push_front(B[i]);
		else {
			list<int>::iterator tmp = ans.begin();
			rep(j, 1, B[i]) {
				if (tmp == ans.end()) {
					judge = false;
					break;
				}
				tmp++;
			}
			if (judge)ans.insert(tmp, B[i]);
			else break;
		}
	}

	if (judge)
		for (list<int>::iterator itr = ans.begin(); itr != ans.end(); itr++)
			cout << *itr << endl;
	else cout << -1 << endl;


	return 0;
}
