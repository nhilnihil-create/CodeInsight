#include<iostream>
#include<string>


using namespace std;

int main() {
	string S;
	cin >> S;
	
	string s_before = S.substr(0, 2);
	string s_after = S.substr(2, 2);

	//cout << s_before << " " << s_after << endl;

	int befor_num = stoi(s_before);
	int after_num = stoi(s_after);

	//cout << befor_num << " " << after_num << endl;

	if (1 <= befor_num && befor_num <= 12) {
		//MMYY
		if (1 <= after_num && after_num <= 12) {
			cout << "AMBIGUOUS" << endl;
		}
		else {
			cout << "MMYY" << endl;
		}
	}
	else if (1 <= after_num && after_num <= 12) {
		//YYMM
		if (1 <= befor_num && befor_num <= 12) {
			cout << "AMBIGUOUS" << endl;
		}
		else {
			cout << "YYMM" << endl;
		}
	}
	else {
		cout << "NA" << endl;
	}
	




}


