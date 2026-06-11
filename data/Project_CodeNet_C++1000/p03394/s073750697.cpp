#include <bits/stdc++.h>

using namespace std;

int se20[] = {2,3,4,5,6,8,9,10,12,14,16,18,20,21,22,24,25,26,27,28};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	if (N >= 20){
		for (int i = 1; i <= N%20; ++i){
			cout << i*30 << ' ';
		}
		for (int i = 0; i < N/20; ++i){
			for (int j = 0; j < 20; ++j){
				cout << se20[j] + i*30 << ' ';
			}
		}
		cout << '\n';
	}
	else{
		if (N == 3){
			cout << 2 << ' ' << 5 << ' ' << 63 << '\n';
		}
		else{
			for (int i = 0; i < N/4; ++i){
				cout << 2 + i*18 << ' ' << 3 + i*(18) << ' ' << 4 + i*18 << ' ' << 9 + i*18 << ' ';
			}
			for (int i = 1; i <= N%4; ++i){
				cout << 6*i << ' ';
			}
			cout << '\n';
		}
	}
	cout << flush;
	//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}



/*
2	
3	
4	
5	
6
8
9
10
12
14
16
18
20
21
22
24
25
26
27
28
30




*/