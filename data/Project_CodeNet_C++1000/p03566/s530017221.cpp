#include<cstdio>

int main(){
	int N;
	scanf("%d", &N);
	int t[N], total_t = 0;
	for (int i = 0; i < N; ++i){
		scanf("%d", t + i);
		total_t += t[i];
	}
	int v_max[total_t*2 + 1];
	for (int i = 0; i <= total_t; ++i) v_max[i] = v_max[total_t*2 - i] = i;
	int time_passed = 0;
	for (int i = 0; i < N; ++i){
		int v;
		scanf("%d", &v);
		for (int j = time_passed*2; j < (time_passed + t[i])*2; ++j) if(v_max[j] > v*2) v_max[j] = v*2;
		for (int j = 1; j < time_passed*2; ++j) if(v_max[j] > v*2 + time_passed*2 - j) v_max[j] = v*2 + time_passed*2 - j;
		for (int j = (time_passed + t[i])*2; j < total_t*2; ++j) if(v_max[j] > v*2 + j - (time_passed + t[i])*2) v_max[j] = v*2 + j - (time_passed + t[i])*2;
		time_passed += t[i];
	}
	int answer = 0;
	for (int i = 0; i < total_t*2; ++i) answer += v_max[i] + v_max[i + 1];
	printf("%lf\n", ((double)answer)/8.0);
	return 0;
}