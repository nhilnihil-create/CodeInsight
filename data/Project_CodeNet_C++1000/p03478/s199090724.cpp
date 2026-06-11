#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int N, A, B;
	cin >> N >> A >> B;

	int num = 0;
	for(int i = 1; i < N + 1; i++){
		int sum = 0;
		int tmp = i;
		while(1){
			sum += tmp % 10;
			tmp = tmp / 10;
			if(tmp == 0)
				break;
		}
		if(sum >= A && sum <= B)
			num += i;
	}
	cout << num << endl;
}
