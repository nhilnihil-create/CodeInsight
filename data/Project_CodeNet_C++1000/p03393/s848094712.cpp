#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<time.h>
#include<set>
#include<map>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define ct(a) cout<<a<<endl
#define tget(a,b) get<a>(b)
using namespace std;
typedef long long ll;
const ll INF = 1e17;
const int MOD = 1e9 + 7;

map<char, bool> mp;
string a;
int ans;
int main(void) {
	cin >> a;
	FOR(i, 0, a.size()) {
		mp[a[i]]=true;
	}
	if (a.size() != 26) {
		FOR(i, 'a', 'z' + 1) {
			if (mp[i] == false) {
				ct(a + char(i));
				return 0;
			}
		}
	}
	else {
		for (int i = 24; i >= 0; i--) {
			char mi = a[i], cur = 'z'+1;
			FOR(k, i + 1, 27) {
				if (mi<a[k] && cur>a[k])cur = a[k];
			}
			if (cur == 'z' + 1)continue;
			swap(a[i], cur);
			ct(a.substr(0, i+1));
			return 0;
		}
	}
	ct(-1);
	return 0;
}
