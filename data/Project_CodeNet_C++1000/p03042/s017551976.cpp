#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int s;
	cin >> s;
	int head = s/100;
	int tail = s%100;

	if(1 <= head && head <= 12 && 1 <= tail && tail <= 12){
		cout << "AMBIGUOUS" << endl;
	}else if(1 <= head && head <= 12){
		cout << "MMYY" << endl;
	}else if(1 <= tail && tail <= 12){
		cout << "YYMM" << endl;
	}else{
		cout << "NA" << endl;
	}

	return 0;
}