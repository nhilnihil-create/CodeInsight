#include <cstdio>
#include <cstring>
#define N 200010
#define mem(x, a) memset(x, a, sizeof x)
#define fo(x, a, b) for (int x = (a); x <= (b); x++)
#define fd(x, a, b) for (int x = (a); x >= (b); x--)
using namespace std;
int n, a[N], b[N], z[N][2];

inline int read() {
	int x = 0, f = 0; char c = getchar();
	while (c < '0' || c > '9') f = (c == '-') ? 1 : f, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? -x : x;
}

void jinwei(int x, int mid) {
	while (b[x] == mid) b[x] = 1, x--;
	b[x]++;
}

bool check(int mid) {
	z[1][0] = a[1], z[1][1] = 1;
	int top = 1;
	fo(i, 2, n) {
		if (a[i] > a[i - 1]) {
			z[++top][0] = a[i], z[top][1] = 1;
			continue;
		}
		while (z[top][0] > a[i]) top--;
		if (z[top][0] == a[i] && top > 0) z[top][1]++;
		else z[++top][0] = a[i], z[top][1] = 2;
		while (z[top][1] > mid && z[top][0] != 0) {
			if (top > 1 && z[top - 1][0] == z[top][0] - 1) z[top - 1][1]++, top--;
			else z[top][0]--, z[top][1] = 2;
		}
		if (z[1][0] == 0) return 0;
	}
	return 1;
}

int main()
{
	n = read();
	fo(i, 1, n) a[i] = read();
	check(2);
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", r + 1);
	return 0;
}
