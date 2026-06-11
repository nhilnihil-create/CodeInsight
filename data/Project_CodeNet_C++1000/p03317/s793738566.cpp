#include<iostream>
#include<vector>
#include<cmath>

/*
int main(){

	int N;
	unsigned long int ans = 0;
	std::cin >> N;

	std::vector<unsigned long int> list(N,0);

	std::vector<unsigned long int> sum(N,0);

	for (int i = 0; i < N;i++){
		std::cin >> list[i];
		if(!i){
			continue;
		}
		for (int j = 0; j <i;j++){
			sum[j] += list[i];
		}
	}


	for (int i = 0; i < N-1; i++){
		ans += (list[i] * sum[i])%1000000007;
	}
	ans %= 1000000007;

	std::cout << ans << std::endl;
}
*/

int main(){
	int N, K;
	std::cin >> N >> K;

	std::vector<int> list(N, 0);

	for (int i = 0; i < N;i++){
		std::cin >> list[i];
	}

	int num = 0;

	for (num = 0; list[num] != 1;num++){
	}

	std::cout << (int)ceil((list.size()-1)*1.0/(K-1)) << std::endl;
}