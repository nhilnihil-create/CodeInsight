#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	string s;
	// nyuryoku
	cin >> s;
	int y = (s[0]-'0')*1000 + (s[1] - '0')*100 + (s[2] - '0')*10 + (s[3] - '0');
	int m = (s[5] - '0')*10 + (s[6]- '0');
	int d = (s[8] - '0')*10 + (s[9] - '0');
 	// keisan
 	if(y < 2019){
 		cout << "Heisei" << endl;
 	}else if(y > 2019){
 		cout << "TBD" << endl;
 	}else if(m > 4){
 		cout << "TBD" << endl;
 	}else{
 		cout << "Heisei" << endl;
 	}
	// syutsuryoku
}