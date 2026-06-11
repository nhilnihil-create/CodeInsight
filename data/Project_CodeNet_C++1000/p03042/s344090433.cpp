#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int s;
	cin >> s;
	
	int num1 = s/100;
	int num2 = s%100;

	if(1 <= num1 && num1 <= 12){
		if(1 <= num2 && num2 <= 12){
			cout << "AMBIGUOUS" << endl;
		}else{
			cout << "MMYY" << endl;
		}
	}else if(1 <= num2 && num2 <= 12){
		cout << "YYMM" << endl;
	}else{
		cout << "NA" << endl;
	}

	return 0;
}
