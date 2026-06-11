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

int n, q;
string s;
char t[200001];
char d[200001];

bool cangoal(int start, int goal)
{
	int now = start;
	for(int i = 0; i < q; i++){
		if(t[i] == s[now]){
			if(d[i] == 'L') now--;
			else now++;
			if(now == goal) return true;
			if(now == -1 || now == n) return false;
		}
	}
	return false;
}


int solve(int goal)
{
	int l = -1;
	int r = n;
	while(r - l > 1){
		int m = (l + r) / 2;
		if(cangoal(m, goal)){
			if(goal == -1) l = m;
			else r = m;
		} else {
			if(goal == -1) r = m;
			else l = m;
		}
	}
	if(goal == -1) return r;
	return l;
}

int main()
{
	cin >> n >> q >> s;
	for(int i = 0; i < q; i++){
		cin >> t[i] >> d[i];
	}

	int l = solve(-1);
	int r = solve(n);
	// (-1, l)と(r, n)がゴールできる範囲
	// つまり、ゴールできないのは[l, r]
	cout << max(0, r - l + 1) << endl;
}