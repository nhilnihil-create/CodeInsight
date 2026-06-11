#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long int llint;

int main(){
	int N;
	cin >> N;
	llint caseCnt=1;

	for(int i=0;i<N;i++){
		int a;
		cin >> a;
		if(a%2==0){
			caseCnt*=2;
		}else{
			caseCnt*=1;
		}
	}

	cout << (pow(3,N)-caseCnt) << endl;
	return 0;
}
