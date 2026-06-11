#include<iostream>
#include<string>
using namespace std;



int main() {
	string s;

	cin >> s;

	string nen = s.substr(0, 4);
	string tsuki = s.substr(5, 2);
	string hi = s.substr(8, 2);
	//cout << atoi(nen.c_str()) << endl;

	//cout << atoi(tsuki.c_str()) << endl;
	if (atoi(nen.c_str()) < 2019) {
		cout << "Heisei" << endl;
		return 0;
	}
	else if (atoi(nen.c_str()) > 2019) {
		cout << "TBD" << endl;
		return 0;
	}
	else {
		if (atoi(tsuki.c_str()) < 4) {
			cout << "Heisei" << endl;
			return 0;
		}
		else if(atoi(tsuki.c_str()) >4){
			cout << "TBD" << endl;
			return 0;
		}
		else {
			if (atoi(hi.c_str()) <= 30) {
				cout << "Heisei" << endl;
				return 0;
			}
			else {
				cout << "TBD" << endl;
			}
		}
	}
	return 0;
}