#include<cstdio>
#include<vector>
using namespace std;

int main(){
	unsigned N, K;
	scanf("%u %u\n", &N, &K);
	bool left_is_upsidedown = false;
	unsigned consecutive = 0;
	vector<unsigned> A;
	A.push_back(0);
	for (unsigned i = 0; i < N; ++i){
		char tmp;
		scanf("%c", &tmp);
		bool this_is_upsidedown = tmp == '1';
		if(left_is_upsidedown ^ this_is_upsidedown){
			A.push_back(consecutive);
			consecutive = 1;
			left_is_upsidedown ^= 1;
		}else{
			consecutive++;
		}
	}
	A.push_back(consecutive);
	unsigned ans = 0, block = A.size();
	for (unsigned i = 1; i <= K*2 && i < block; ++i){
		ans += A[i];
	}
	unsigned candidate = ans;
	for (int i = 0; i*2 + K*2 + 1 < block; ++i){
		candidate = candidate + A[i*2 + K*2 + 1] - A[i*2] - A[i*2 + 1];
		if(i*2 + K*2 + 2 < block) candidate += A[i*2 + K*2 + 2];
		if(ans < candidate) ans = candidate;
	}
	printf("%u\n", ans);
	return 0;
}