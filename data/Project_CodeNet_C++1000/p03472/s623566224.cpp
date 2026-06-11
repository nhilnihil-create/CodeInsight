#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int N, H;
	scanf("%d %d", &N, &H);
	int max_a = 0, b[N];
	for (int i = 0; i < N; ++i){
		int tmp;
		scanf("%d %d", &tmp, b + i);
		if(max_a < tmp) max_a = tmp;
	}
	sort(b, b + N);
	int begin = distance(b, lower_bound(b, b + N, max_a));
	int answer = 0;
	while(H > 0 && N > begin){
		H -= b[--N];
		answer++;
	}
	if(H > 0) answer += (H - 1)/max_a + 1;
	printf("%d\n", answer);
	return 0;
}