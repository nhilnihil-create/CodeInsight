#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

using namespace std;

typedef long long int lli;

int gcd(int a, int b){
	return b != 0 ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
	return a*b / gcd(a, b);
}

#define N_MAX 5
#define MOD 1000000007

void solv()
{
	int N; scanf("%d", &N);

	int M;
	if (0 == N % 2){
		M = N*(N - 1) / 2 - N / 2;
		printf("%d\n", M);
		for (int i = 1; i <= N; i++){
			for (int j = i + 1; j <= N; j++){
				if (i + j != (N + 1)){
					printf("%d %d\n", i, j);
				}
			}
		}
	}
	else{
		M = N*(N - 1) / 2 - (N - 1) / 2;
		printf("%d\n", M);
		for (int i = 1; i <= N; i++){
			for (int j = i + 1; j <= N; j++){
				if (i + j != N){
					printf("%d %d\n", i, j);
				}
			}
		}
	}

	return;
}

int main()
{
	FILE *fin = NULL, *fout = NULL;
	//fin = freopen("input.txt", "r", stdin);
	//fout = freopen("output.txt", "w", stdout);

	solv();

	//finalize
	if (NULL != fin) fclose(fin);
	if (NULL != fout) fclose(fout);

	return 0;
}