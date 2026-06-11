#include <map> 
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr << "<<< " << #x << " = " << x << endl
using namespace std;

int const N = 40;
int n;
char ch[N];
map < pair <string, string>, long long> cnt;

int main() {
//	freopen("hh.txt", "r", stdin);
//	double st = clock();
	scanf("%d", &n);
	scanf("%s", ch);
	for (int i = 0; i < (1 << n); i++) {
		string s1 = "", s2 = "";
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) s1 += ch[j];	//s1保存正向的 
			else s2 += ch[j];
		}
		cnt[make_pair(s1, s2)]++;
	}
	
	long long ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		string s1 = "", s2 = "";
		for (int j = n - 1; j >= 0; j--) {
			if (i & (1 << j)) s2 += ch[j + n];
			else s1 += ch[j + n];
		}
		ans += cnt[make_pair(s1, s2)];
	}
	printf("%lld\n", ans);
//	printf("%.lf\n", clock() - st);
	return 0;
}