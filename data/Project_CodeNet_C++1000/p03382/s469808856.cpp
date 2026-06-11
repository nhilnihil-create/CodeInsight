#include<iostream>
#include<iomanip>
//#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cassert>
using namespace std;
typedef long long ll;
int N;
ll A[100000];

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> A[i];
	}

	sort(A, A+N);
	int b = A[0];
	for(int i=0; i<N-1; i++){
		if(abs(A[N-1]-2*A[i]) < abs(A[N-1]-2*b)){
			b = A[i];
		}
	}

	cout << A[N-1] << " " << b << endl;

	return 0;
}
