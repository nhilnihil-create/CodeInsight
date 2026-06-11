#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;

	if (N == 3) printf("2 5 63\n");
	else if (N == 4) printf("2 5 20 63\n");
	else if (N == 5) {
		printf("2 5 20 63 30\n");
	}
	else{
		ll sum = 0;
		int tot = 0, num = 2, cnt = 0;
		map<int, bool> mp;
		while (cnt < N) {
			if (num % 2 == 0 || num % 3 == 0) {
				mp[num] = true;
				cnt++;
				tot += num;
				tot %= 6;
				sum += num;
			}
			num++;
		}

		//cout << "tot1=" << tot << endl;
		//cout << "sum1=" << sum << endl;
		if (tot % 6 == 2) {
			mp[8] = false;
			while (num % 6 != 0) {
				num++;
			}
			mp[num] = true;
			sum += num-8;
			tot = (tot + num-8) % 6;
		}

		else if (tot % 6 == 3) {
			mp[9] = false;
			while (num % 6 != 0) {
				num++;
			}
			mp[num] = true;
			sum += num-9;
			tot = (tot + num-9) % 6;
		}

		else if (tot % 6 == 5) {
			mp[8] = false;
			while (num % 6 != 3) {
				num++;
			}
			mp[num] = true;
			sum += num-8;
			tot = (tot + num-8) % 6;
		}
		
		//cout << "tot2=" << tot << endl;
		//cout << "sum2=" << sum << endl;
		for (int i = 2; i <= 3e4; i++) {
			if (mp[i])cout << i << " ";
		}
		cout << endl;
	}
}
