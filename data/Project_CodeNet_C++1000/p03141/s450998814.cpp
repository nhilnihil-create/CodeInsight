#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define N_MAX 100001

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	int N;
	scanf("%d", &N);

	long long int table[N_MAX], bsum = 0;
	for (int i = 0; i < N; i++){
		int a, b; scanf("%d%d", &a, &b);
		table[i] = -(a + b);
		bsum += b;
	}

	sort(table, table + N);

	long long int ret = -bsum;
	for (int i = 0; i < N; i+=2){
		ret -= table[i];
	}

	printf("%lld", ret);

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}