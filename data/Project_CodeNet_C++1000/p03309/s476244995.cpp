#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
	unsigned N;
	scanf("%d", &N);
	int A[N];
	for (int i = 0; i < N; ++i){
		scanf("%d", A + i);
		A[i] -= i+1;
	}
	sort(A, A + N);
	ll b = (A[N-1>>1] + A[N>>1])/2;
	ull ans = 0;
	for (int i = 0; i < N; ++i){
		ans += abs(A[i] - b);
	}
	printf("%llu\n", ans);
	return 0;
}