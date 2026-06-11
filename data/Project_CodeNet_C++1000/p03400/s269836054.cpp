/**
 * Author  : dhakad_123
 * Created : 15.08.2020
 **/

#include<bits/stdc++.h>
using namespace std;

int total(int i , int d){

	int cnt = 0;
	int k = 1;

	while(k <= d){
		cnt++;
		k += i;
	}

	return  cnt;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int N , D , X;
	cin >> N;

	cin >> D >> X;

	vector<int>A(N);

	int ans = 0;


	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	
        for(int i = 0; i < N; i++){

		ans += total(A[i] ,D);
	}

	cout << ans + X << endl;

	return 0;
}

