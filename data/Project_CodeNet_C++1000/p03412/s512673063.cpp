#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int a[N], b[N];
	for (int i = 0; i < N; ++i) scanf("%d", a + i);
	for (int i = 0; i < N; ++i) scanf("%d", b + i);
	int answer = 0, T = 1 << 28;
	bool digit = false;
	sort(b, b + N);
	for (int i = 0; i < N; ++i)	digit ^= distance(lower_bound(b, b + N, T - a[i]), b + N) & 1;
	if(digit) answer += T;
	T >>= 1;
	digit = false;
	for (int i = 0; i < N; ++i)	digit ^= (distance(lower_bound(b, b + N, T - a[i]), lower_bound(b, b + N, T*2 - a[i])) ^ distance(lower_bound(b, b + N, T*3 - a[i]), b + N)) & 1;
	if(digit) answer += T;
	for (int i = 27; i > 0; --i){
		T >>= 1;
		digit = false;
		for (int j = 0; j < N; ++j){
			a[j] %= (1 << i);
			b[j] %= (1 << i);
		}
		sort(b, b + N);
		for (int j = 0; j < N; ++j)	digit ^= (distance(lower_bound(b, b + N, T - a[j]), lower_bound(b, b + N, T*2 - a[j])) ^ distance(lower_bound(b, b + N, T*3 - a[j]), b + N)) & 1;
		if(digit) answer += T;
	}
	printf("%d\n", answer);
	return 0;
}