#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void c_not_so_diverse(void) {
	int n, k;
	int *a;

	cin >> n >> k;

	a = (int*)(calloc(n, sizeof(int)));

	for (int i = 0; i < n; i++) cin >> a[i];

	//int b[200000] = { 0 };
	int* b;
	b = (int*)(calloc(n+1, sizeof(int)));


	for (int i = 0; i < n; i++) b[a[i]]++;
	sort(b, b + n+1);

	int type_cnt = 0;
	int k_cnt = 0;
	for (int i = 0; i < n+1; i++) {
		if (b[i] == 0) continue;
		type_cnt++;
	}
	//cout << type_cnt << endl;
	int cnt = 0;
	for (int i = 0; i < n+1; i++) {
		if (k_cnt >= (type_cnt - k)) break;
		if (b[i] == 0)continue;
		//cout << b[i] << endl;
		cnt += b[i];
		k_cnt++;
	}

	cout << cnt << endl;

	//free(a);
	//free(b);
}

int main()
{
	c_not_so_diverse();
    return 0;
}