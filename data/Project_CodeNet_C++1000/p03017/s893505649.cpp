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
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;

int main(void)
{
	int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
	string S; cin >> S;
	bool flag = true;


	rep(i, B - 1, D - 1)if (S[i] == '#' && S[i + 1] == '#') {
		flag = false;
		break;
	}
	rep(i, A - 1, C - 1)if (S[i] == '#' && S[i + 1] == '#') {
		flag = false;
		break;
	}

	if (D < C) {
		bool three = false;
		rep(i, B - 2, D - 1)
			if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
				three = true;
				break;
			}
		if (!three)flag = false;
	}

	cout << (flag ? "Yes" : "No") << endl;


	return 0;
}
