#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	int H, W, N;
	cin >> H >> W >> N;
	int X[N], Y[N];
	int low[H];
	for(int i=0; i<H; i++){
		low[i] = 200001;
	}
	for(int i=0; i<N; i++){
		cin >> X[i] >> Y[i];
		if(low[X[i]-1] > Y[i]){
			low[X[i]-1] = Y[i];
		}
	}
	int possible[H];
	possible[0] = 1;
	for(int i=1; i<H; i++){
		if(low[i] <= possible[i-1]){
			cout << i << endl;
			return 0;
		}
		if(low[i] == possible[i-1]+1){
			possible[i] = possible[i-1];
		}else{
			possible[i] = possible[i-1]+1;
		}
	}
	cout << H << endl;
	return 0;
}