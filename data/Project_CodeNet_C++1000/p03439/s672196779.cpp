#include <bits/stdc++.h>
using namespace std;



int main() {
	int begin;
	int last;
	int middle;
	int number;

	string type_begin;

	string type_last;
	string type_middle;

	begin = 0;
	cin >> last;
	cout << 0 << endl;
	cin >> type_begin;
	if (type_begin == "Vacant") {

		cout << begin << endl;
		return 0;
	}

	type_last = type_begin;
	for (int i=0;i <= 20;i++) {

		middle = (begin+last)/2;
		cout << middle << endl;
		cin >> type_middle;
		number = middle - begin + 1;
		if (type_middle== "Vacant") {
		
			cout << begin << endl;
			return 0;
		}
		else if (((number % 2 == 0) && (type_begin == type_middle)) || ((number % 2 == 1) && (type_begin != type_middle))) {
			last = middle;
			type_last = type_middle;
		}

		else if (((number % 2 == 1) && (type_begin == type_middle)) || ((number % 2 == 0) && (type_begin != type_middle))) {
			begin = middle;
			type_begin = type_middle;
		}


		

	
	}


	return 0;

}


