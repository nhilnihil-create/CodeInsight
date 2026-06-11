#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>  
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD  998244353
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
#define int long long
	int n;
	cin >> n;
	string s;
	cin >> s;
	int query;
	cin >> query;
	REP(tea, query) {
		int border = 0;
		cin >> border;
		long long ans = 0;
		long long now_d = 0;
		long long now_m = 0;
		long long now_value = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == 'D') {
				now_d++;
			}
			else if (s[i] == 'C') {
				ans += now_value;
			}
			else if (s[i] == 'M') {
				now_value += now_d;
				now_m++;
			}
			if (i >= border - 1) {
				int nexter = i - border + 1;
				if (s[nexter] == 'D') {
					now_value -= now_m;
					now_d--;
				}
				else if (s[nexter] == 'M') {
					now_m--;
				}
			}
		}
		cout << ans << endl;
	}
}
