#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	string s;
	// nyuryoku
	cin >> s;
	// keisan
	int a = (s[0] - '0')*10 + (s[1] - '0');
	int b = (s[2] - '0')*10 + (s[3] - '0');
	if(a*b == 0){
		if(a > 12 || b > 12){
			cout << "NA" << endl;
		}else if(a > b){
			cout << "MMYY" << endl;
		}else if(b > a){
			cout << "YYMM" << endl;
		}else{
			cout << "NA" << endl;
		}
	}else if(a <13 && b <13){
		cout << "AMBIGUOUS" << endl;
	}else if(a > 12 && b > 12){
		cout << "NA" << endl;
	}else if(a < 13){
		cout << "MMYY" << endl;
	}else{
		cout << "YYMM" << endl;
	}
	// syutsuryoku
}