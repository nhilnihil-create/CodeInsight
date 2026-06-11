#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_yymm_or_mmyy(void) {
	string s;
	cin >> s;
	int upper, lower;
	string sub_s;
	sub_s = s.substr(0, 2);
	upper = stoi(sub_s);
	sub_s = s.substr(2, 2);
	lower = stoi(sub_s);

	string upper_type, lower_type;
	if (upper > 12) {
		upper_type = "YY";
	}
	else if (upper == 0) {
		upper_type = "YY";
	}
	else {
		upper_type = "MM";
	}
	if (lower > 12) {
		lower_type = "YY";
	}
	else if (lower == 0) {
		lower_type = "YY";
	}
	else {
		lower_type = "MM";
	}
	
	if (upper_type == "YY" && lower_type == "MM")      cout << "YYMM" << endl;
	else if (upper_type == "MM" && lower_type == "YY") cout << "MMYY" << endl;
	else if (upper_type == "YY" && lower_type == "YY") cout << "NA" << endl;
	else                                               cout << "AMBIGUOUS" << endl;
}

int main()
{
    b_yymm_or_mmyy();

    return 0;
}
