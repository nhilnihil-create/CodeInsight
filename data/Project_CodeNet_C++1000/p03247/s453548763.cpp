#include<bits/stdc++.h>
using namespace std;
inline int read () {
	int num = 0;
	char c = ' ';
	bool flag = true;
	for (;c > '9' || c < '0';c = getchar())
		if (c == '-')
			flag = false;
	for (;c >= '0' && c <= '9';num = (num << 1) + (num << 3) + c - 48, c = getchar());
	return flag ? num : -num;
}
namespace INIT {
	const int maxn = 1020;
	struct ques {
		long long x, y;
	} q[maxn];
	int n;
	void init () {
		n = read ();
		for (int i = 1;i <= n;i ++)
			q[i].x = read(), q[i].y = read ();
	}
} using namespace INIT;

namespace CHECK {
	bool odd = 0;
	void check () {
		for (int i = 1;i < n;i ++)
			if (((q[i].x + q[i].y) & 1) != ((q[i + 1].x + q[i + 1].y) & 1)) {
				printf ("%d\n", -1);
				exit (0);
			}
		odd = (q[1].x + q[1].y) & 1;
	}
} using namespace CHECK;

namespace get_Di {
	long long d[50]; int m = 0;
	void work1 () {
		d[++ m] = 1;
		while (d[m] <= 1e9)
			d[++ m] = 1ll * d[m - 1] << 1;
		if (!odd) d[++ m] = 1;
		printf ("%d\n", m);
		for (int i = 1;i <= m;i ++)
			printf ("%lld ",d[i]);
		printf ("\n");
	}
} using namespace get_Di;

namespace get_direct {
	inline double dis (long long x, long long y) {
		return sqrt ((double)x * x + (double)y * y);
	}
	vector <char> ans;
	void work2 () {
		for (int i = 1;i <= n; i ++) {
			ans.clear ();
			long long x = q[i].x;
			long long y = q[i].y;
			for (int j = m;j >= 1;j --)
				if (abs (x) > abs (y)) {
					if (x < 0) {
						ans.push_back ('L');
						x += d[j];
					}
					else {
						ans.push_back ('R');
						x -= d[j];
					}
				}
				else {
					if (y < 0) {
						ans.push_back ('D');
						y += d[j];
					}
					else {
						ans.push_back ('U');
						y -= d[j];
					}
				}
			for (int i = ans.size () - 1;i >= 0;i --)
				printf ("%c",ans[i]);
			printf ("\n");
		}
	}
} using namespace get_direct;
int main () {
	init ();
	check ();
	work1 ();
	work2 ();
	return 0;
}