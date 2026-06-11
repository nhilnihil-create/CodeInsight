#include <iostream>

using namespace std;

int main(){
	int N, M;
	cin >> N >> M;

	int likeCounter[M] = {0};

	for (int i = 0; i < N; i++){
		int K;
		cin >> K;

		for (int j = 0; j < K; j++){
			int A;
			cin >> A;
			A--;

			likeCounter[A]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++){
		if(likeCounter[i] == N){
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
