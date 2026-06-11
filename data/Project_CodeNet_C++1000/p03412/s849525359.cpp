#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
typedef long long ll;
using namespace std;

int n, a[200000], a2[200000], b[200000], b2[200000], cnt[30], l, r, ans;

int main() {
	cin >> n;
	lp(n)
		cin >> a[i];
	lp(n)
		cin >> b[i];
	lp(30)
		cnt[i] = 0;
	lp(29) {
		LP(n,j) {
			a2[j] = a[j] % (1 << (i + 1));
			b2[j] = b[j] % (1 << (i + 1));
		}
		sort(b2, b2 + n);
		LP(n, j) {
			l = -1;
			r = n;
			while (l + 1 != r) {
				if (b2[(l + r) / 2] + a2[j] < 1 << i)l = (l + r) / 2;
				else r = (l + r) / 2;
			}
			cnt[i] -= l;
			l = -1;
			r = n;
			while(l+1!=r){
				if (b2[(l + r) / 2] + a2[j] < 1 << (i + 1))l = (l + r) / 2;
				else r = (l + r) / 2;
			}
			cnt[i] += l;
			l = -1;
			r = n;
			while (l + 1 != r) {
				if (b2[(l + r) / 2] + a2[j] < (1 << i) + (1 << (i + 1)))l = (l + r) / 2;
				else r = (l + r) / 2;
			}
			cnt[i] += n - 1 - l;
		}
	}
	ans = 0;
	lp(30)
		if (cnt[i] % 2)ans += 1 << i;
	cout << ans << endl;
	return 0;
}
