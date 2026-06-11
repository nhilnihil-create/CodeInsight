#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N,M;
	cin >> N >> M;

	vector<int> X(M);
	for(int i = 0; i < M; i++){
		cin >> X.at(i);
	}
	
	if(N >= M){
		cout << 0 << endl;
		return 0;
	}
	
	
	sort(X.begin(), X.end());
	
	//dist.at(i)は、iとi+1の距離
	vector<int> dist(M-1);
	for(int i = 0; i < M-1; i++){
		dist.at(i) = abs(X.at(i+1) - X.at(i));
	}
	
	sort(dist.begin(), dist.end());
	
	//でかい区間から順に区切り線で消す
	for(int i = 0; i < N-1; i++){
		dist.at(M - (2+i)) = 0;
	}
	
	int ans = 0;
	for(int i = 0; i < M-1; i++){
		ans += dist.at(i);
	}
	
	cout << ans << endl;
	
}