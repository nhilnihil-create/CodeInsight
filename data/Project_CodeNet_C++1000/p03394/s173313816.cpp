#include<bits/stdc++.h>
using namespace std;

vector < int > pot[6];

int main(){
	vector < int > arr;
	for(int i = 2 ; i <= 30000 ; ++i)
		if(i % 2 == 0 || i % 3 == 0) pot[i % 6].push_back(i);
	int N; cin >> N;
	if(N == 3){printf("2 5 63"); return 0;}
	if(N == 4){printf("2 5 20 63"); return 0;}
	cout << pot[3][0] << ' ' << pot[3][1] << ' '; N -= 2;
	for(int i = 0 ; N && i < 5000 ; ++i){
		--N; cout << pot[0][i] << ' ';
		if(N % 2 == 0 && N <= 14998) break;
	}
	for(int i = 0 ; i < 5000 && N ; ++i){
		cout << pot[2][i] << ' ' << pot[4][i] << ' ';
		N -= 2;
	}
	for(int i = 2 ; i <= 5000 && N ; i += 2){
		N -= 2; cout << pot[3][i] << ' ' << pot[3][i + 1] << endl;
	}
	return 0;
}