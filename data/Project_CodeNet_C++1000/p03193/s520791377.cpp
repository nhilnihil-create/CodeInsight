#include<cstdio>
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main(){
	int N, count = 0;
	int H, W;
	cin >> N >> H >> W;
	long int A[N], B[N];
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
		if(A[i] >= H && B[i] >= W){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}