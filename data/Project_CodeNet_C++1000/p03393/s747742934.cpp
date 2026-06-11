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

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;

int main(void)
{
	string S; cin >> S;
	map<char, bool> rec;
	rep(i, 0, 26)rec['a' + i] = false;
	if (S == "zyxwvutsrqponmlkjihgfedcba")cout << -1 << endl;
	else {
		if (S.size() == 26) {
			int k = 25;
			while (S[k - 1] >= S[k])k--;
			rep(i, 0, k)rec[S[i]] = true;
			char end = S[k - 1];
			while (rec[end])end++;
			string ans = S.substr(0, k - 1) + end;
			cout << ans << endl;
		}
		else {
			rep(i, 0, S.size())rec[S[i]] = true;
			char end = 'a';
			while (rec[end])end++;
			cout << S + end << endl;
			//for (map<char, bool>::iterator it = rec.begin(); it != rec.end(); it++)
				//cout << it->first << " " << (it->second ? "ON" : "OFF") << endl;
		}

	}

	return 0;
}
