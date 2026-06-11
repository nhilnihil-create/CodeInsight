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

long long int cntb[1000001] = {};
long long int cntc[1000001] = {};
long long int cntcb[1000001] = {};
long long int sumcb[1000001] = {};

int main()
{
	int n, q;
	string s;
	cin >> n >> s >> q;
	// cntb[i] : 0文字目からi - 1文字目までのbの出現回数
	for(int i = 1; i <= n; i++){
		cntb[i] = cntb[i - 1];
		if(s[i - 1] == 'M') cntb[i]++;
	}
	// cntc[i] : 0文字目からi - 1文字目までのcの出現回数
	// cntcb[i] : 最後のcがi - 1文字目になるようなbcの組み合わせ
	// sumcb[i] : cntcb[0] + ... + cntcb[i - 1]
	for(int i = 1; i <= n; i++){
		cntc[i] = cntc[i - 1];
		if(s[i - 1] == 'C'){
			cntcb[i] = cntb[i - 1];
			cntc[i]++;
		}
		sumcb[i] = sumcb[i - 1] + cntcb[i];
		// cout << i << " " << sumcb[i] << endl;
	}

	for(int i = 0; i < q; i++){
		int k;
		cin >> k;
		long long int ans = 0;
		for(int j = 0; j < n; j++){
			if(s[j] != 'D') continue;
			ans += sumcb[min(j + k, n)] - sumcb[j] - ((cntc[min(j + k, n)] - cntc[j]) * cntb[j]);
			// cout << sumcb[min(j + k, n)] - sumcb[j] - ((cntc[min(j + k, n)] - cntc[j]) * cntb[j]) << endl;
		}
		cout << ans << endl;
	}
}