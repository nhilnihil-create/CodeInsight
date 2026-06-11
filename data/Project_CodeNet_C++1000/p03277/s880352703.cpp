#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void merge_sort (int array[], int left, int right) {
  int i, j, k, mid;
  int work[100000];  // 作業用配列
  if (left < right) {
    mid = (left + right)/2; // 真ん中
    merge_sort(array, left, mid);  // 左を整列
    merge_sort(array, mid+1, right);  // 右を整列
    for (i = mid; i >= left; i--) { work[i] = array[i]; } // 左半分
    for (j = mid+1; j <= right; j++) {
      work[right-(j-(mid+1))] = array[j]; // 右半分を逆順
    }
    i = left; j = right;
    for (k = left; k <= right; k++) {
      if (work[i] < work[j]) { array[k] = work[i++]; }
      else                   { array[k] = work[j--]; }
    }
  }
}

class segTree {
public:
	long long N;
	int *T;
	void init(int num) {
		N = 1;
		while (N < num) {
			N *= 2;
		}
		T = (int *)calloc((2 * N - 1), sizeof(int));
	}
	int act(int l, int r) {
		return l + r;
	}
	void add(int x, int v) {
		long long k = x + N - 1;
		T[k] += v;
		while (k > 0) {
			k = int(floor((k - 1) / 2));
			T[k] += v;
		}
	}
	int getV(int l, int r) {
		return getVs(l, r, 0, 0, N - 1);
	}
	int getVs(int l, int r, int k, int kl, int kr) {
		if (l <= kl && r >= kr) {
			return T[k];
		}
		int t = int(floor((kl + kr) / 2));
		if (l > t) {
			return getVs(l, r, 2 * k + 2, t + 1, kr);
		}
		if (r < t + 1) {
			return getVs(l, r, 2 * k + 1, kl, t);
		}
		return act(getVs(l, r, 2 * k + 1, kl, t),
			getVs(l, r, 2 * k + 2, t + 1, kr));
	}
	~segTree()
	{
		free(T);
	}
};

bool judge(int x, long long N, int *a) {
	int *v;
	v = (int *)malloc((N + 1) * sizeof(int));
	int mi = 0;
	int ma = 0;
	v[0] = 0;
	for (int i = 0; i < N; i++) {
		v[i + 1] = v[i] + (a[i] < x ? -1 : 1);
		if (mi > v[i + 1])
			mi = v[i + 1];
		if (ma < v[i + 1])
			ma = v[i + 1];
	}
	segTree b;
	b.init(ma - mi + 1);

	long long Ans = 0;
	for (int i = 0; i < N + 1; i++) {
		Ans += b.getV(0, v[i] - mi);
		b.add(v[i] - mi, 1);
	}
	return Ans >= N * (N + 1) / 4;
}

int main()
{
	int N;
	scanf("%d", &N);
	int *a;
	int *b;
	a = (int *)malloc(N * sizeof(int));
	b = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
  	merge_sort(b, 0, N - 1);
	int re = b[0];
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (b[i] != re) {
			re = b[i];
			b[cnt] = b[i];
			cnt++;
		}
	}
	int ok = 0;
	int ng = cnt;
	int mid;
	while (ng - ok > 1) {
		mid = int(floor((ok + ng) / 2));
		if (judge(b[mid], N, a)) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	printf("%d\n", b[ok]);
}
