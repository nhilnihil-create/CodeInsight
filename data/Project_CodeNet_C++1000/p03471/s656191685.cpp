#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, Y;
	cin >> N >> Y;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N-i; j++){
			int k = N - i - j;
			if(Y == i*10000 + j*5000 + k*1000){
				cout << i << " " << j << " " << k << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;

}












