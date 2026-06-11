#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s; //長さ4の数字列
	vector<string> month = { //月
		"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"
	};

	cin >> s;
	
	string sub_s1 = s.substr(0, 2);
	string sub_s2 = s.substr(2, 4);
	int all_result1 = -100;
	int all_result2 = -100;

	for (int i = 0; i < month.size(); i++) {
		int result1 = month[i].compare(sub_s1);
		int result2 = month[i].compare(sub_s2);
		
		if (result1 == 0 && result2 == 0) {
			all_result1 = result1;
			all_result2 = result2;
		}
		else if (result1 == 0) {
			all_result1 = result1;
		}
		else if (result2 == 0) {
			all_result2 = result2;
		}
	}
	
	if (all_result1 == 0 && all_result2 == 0) {
		cout << "AMBIGUOUS" << endl;
	}
	else if (all_result1 == 0) {
		cout << "MMYY" << endl;
	}
	else if (all_result2 == 0) {
		cout << "YYMM" << endl;
	}
	else {
		cout << "NA" << endl;
	}

}