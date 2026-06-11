#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(long long int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 2000000000
#define LLINF 9000000000000000000
#define PI 3.14159265358979

using namespace std;
typedef long long int ll;
typedef pair<long long int, long long int> P;



int main(void) {
	string s;
	int count[3] = {};

	cin >> s;
	FOR(i, 0, s.size() - 1) {
		count[s[i] - 'a']++;
	}

	sort(count, count + 3);
	if (count[0] + 2 <= count[2]) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}


	return 0;
}