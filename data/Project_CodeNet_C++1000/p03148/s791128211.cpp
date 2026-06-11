#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;

int main() {
	
	long long int n,k;
	cin >> n>>k;
	vector<pair<int,int>>p(n);
	for (int i = 0; i < n; i++) {
		int t, d;
		cin >> t >> d;
		p[i].first = d; p[i].second = t;
	}
	
	sort(p.rbegin(), p.rend());
	vector<bool>f(n + 1);
	long long int ans = 0;
	stack<int>s;
	int cnt = 0;
	long long int tp = 0;
	long long int res = 0;
	for (int i = 0; i < n; i++) {

		if (cnt < k) {

			if (!f[p[i].second]) {
				tp++;
				f[p[i].second] = 1;
			}
			else {
				s.push(p[i].first);
			}
			res += p[i].first;
			cnt++;
			ans = max(ans, res + tp*tp);

		}
		else {
			if (!s.size())break;
			if (f[p[i].second])continue;
			f[p[i].second] = 1;
			tp++;
			res -= s.top();
			res += p[i].first;
			s.pop();
			ans = max(ans, res + tp*tp);
		}
	//	cout << res << endl;
	}


	cout << ans << endl;

	return 0;


}