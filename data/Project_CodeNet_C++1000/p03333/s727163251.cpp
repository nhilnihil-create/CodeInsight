#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <bitset>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int

#include <nmmintrin.h>
#ifdef _MSC_VER

#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

int cous(int a) {
	int ret = 0;
	while (a) {
		ret += a % 10;
		a /= 10;
	}
	return ret;
}


int main() {
	int n;
	cin >> n;

	vector<pii> ku(n);
	multiset<pii, greater<pii>> lt,ltb;
	multiset<pii> rt,rtb;
	REP(i, n) {
		int l, r;
		scanf("%d %d", &ku[i].first, &ku[i].second);
		lt.insert({ku[i].first,ku[i].second});
		rt.insert({ ku[i].second,ku[i].first});
	}

	
	ll ans = 0;
	{
		ll k = 0;
		bool cp = true;
		ltb = lt;
		rtb = rt;
		int pp = 0;
		REP(i, n) {
			if (cp) {
				pii cur = *lt.begin();

				if (cur.first > pp || cur.second < pp) {

					k += cur.first - pp;
					pp = cur.first;
				}

				lt.erase(lt.find(cur));
				rt.erase(rt.find({ cur.second,cur.first }));
			}
			else {
				pii cur = *rt.begin();
				swap(cur.first, cur.second);
				if (cur.first > pp || cur.second < pp) {

					k += pp - cur.second;
					pp = cur.second;
				}

				lt.erase(lt.find(cur));
				rt.erase(rt.find({ cur.second,cur.first }));
			}
			cp = !cp;
		}

		ans = k + abs(pp);
	}


	{
		ll k = 0;
		bool cp = false;
		lt = ltb;
		rt = rtb;
		int pp = 0;
		REP(i, n) {
			if (cp) {
				pii cur = *lt.begin();

				if (cur.first > pp || cur.second < pp) {

					k += cur.first - pp;
					pp = cur.first;
				}

				lt.erase(lt.find(cur));
				rt.erase(rt.find({ cur.second,cur.first }));
			}
			else {
				pii cur = *rt.begin();
				swap(cur.first, cur.second);
				if (cur.first > pp || cur.second < pp) {

					k += pp - cur.second;
					pp = cur.second;
				}

				lt.erase(lt.find(cur));
				rt.erase(rt.find({ cur.second,cur.first }));
			}
			cp = !cp;
		}
		ans = max(ans, k + abs(pp));
	}

	cout << ans << endl;
	return 0;
}
