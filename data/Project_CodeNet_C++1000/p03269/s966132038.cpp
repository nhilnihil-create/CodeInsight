#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int L;

int main(){
	vector<int> v;
	int base = 1;
	while(base < 1000000){
		v.push_back(base);
		base *= 3;
	}
	
	scanf("%d", &L);
	int N = 0; base = 1;
	while((2 * base) - 1 <= L){
		base *= 3;
		N++;
	}
	vector<int> va, vb, vc;
	base = 1;
	int max_3base = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++){
			if(base * (j + 1) - 1 <= L - 1){
				va.push_back(i + 1);
				vb.push_back(i + 2);
				vc.push_back(base * j);
				max_3base = max(max_3base, base * (j + 1));
			}
		}
		base *= 3;
	}
	int diff = L - max_3base;
	for(int i = N - 1; i >= 0; i--){
		if(diff >= v[i]){
			for(int j = 0; j < diff / v[i]; j++){
				va.push_back(i + 1);
				vb.push_back(N + 1);
				vc.push_back(max_3base);
				max_3base += v[i];
			}
			diff -= diff / v[i] * v[i];
		}
	}
	printf("%d %d\n", N + 1, va.size());
	for(int i = 0; i < va.size(); i++){
		printf("%d %d %d\n", va[i], vb[i], vc[i]);
	}
	return 0;
}