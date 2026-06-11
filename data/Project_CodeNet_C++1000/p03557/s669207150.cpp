#include<cstdio>
#include<algorithm>
using namespace std;
using ull = unsigned long long;

int main(){
	int N;
	scanf("%d", &N);
	unsigned A[N], B[N], C[N];
	for (int i = 0; i < N; ++i) scanf("%u", A + i);
	for (int i = 0; i < N; ++i) scanf("%u", B + i);
	for (int i = 0; i < N; ++i) scanf("%u", C + i);
	sort(A, A + N);
	sort(B, B + N);
	sort(C, C + N);
	ull answer = 0;
	for (int i = 0; i < N; ++i) answer += distance(A, lower_bound(A, A + N, B[i]))*distance(upper_bound(C, C + N, B[i]), C + N);
	printf("%llu\n", answer);
	return 0;
}