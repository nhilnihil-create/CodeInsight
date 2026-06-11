#include <iostream>
#include <cmath>
using namespace std;

bool dp[100001];
bool dp2[100001];
//state represents if it possible for player K to win if we consider a prefix of length i of the input with a pile of size J
int a[101];
int main(){
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < N; i++){
		dp[a[i]]=true;
	}
	for(int i = 0; i <= K; i++){
		for(int j = 0; j < N; j++){
			if(i-a[j]<0){continue;}
			if(!dp[i-a[j]]){
				dp[i]=true;
			}
		}
	}

	if(!dp[K]){
		cout << "Second" << endl;
	} else {
		cout << "First" << endl;
	}

}
