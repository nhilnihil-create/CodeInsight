#include <iostream>
#include <string>

using namespace std;

int main(){
	string S;
	cin >> S;

	if(S[5] == '0' && S[6] < '5'){
		cout << "Heisei" << endl;
	} else {
		cout << "TBD" << endl;
	}

	return 0;
}
