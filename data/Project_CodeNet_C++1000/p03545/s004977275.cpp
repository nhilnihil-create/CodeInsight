#include<bits/stdc++.h>
using namespace std;

int number(string &formula, int &index) {
	int value = 0;
	for(int i=index; i<(int)formula.size(); i++) {
		if(isdigit(formula.at(i))) {
			value = value * 10 + stoi(formula.substr(i,1));
			index++;
		}
		else {
			break;
		}
	}
	return value;
}

int formula1(string &formula, int &index) {
	int value = 0;
	value += number(formula, index);
	while(1) {
		if((int)formula.size() == index) {
			break;
		}

		if(formula.at(index) == '+') {
			index++;
			value += number(formula, index);
		}
		else if(formula.at(index) == '-') {
			index++;
			value -= number(formula, index);
		}
		else {
			break;
		}
	}
	return value;
}

int main(void) {
	string num = "";
	int goal = 7;

	cin >> num;

	vector<string> formulas(1<<3);
	for(int bits=0; bits<(1<<3); bits++) {
		bitset<3> s(bits);
		string op;
		string formula = "";

		for(int i=0; i<3; i++) {
			if(s.test(i)) {
				op.push_back('+');
			}
			else {
				op.push_back('-');
			}
		}

		for(int i=0; i<4; i++) {
			if(i == 3) {
				formula += num.at(i);
			}
			else {
				formula += num.at(i);
				formula.push_back(op.at(i));
			}
		}

		formulas.push_back(formula);
	}

	for(string f : formulas) {
		int index = 0;
		if(formula1(f, index) == goal) {
			cout << f << "=" << goal << endl;
			break;
		}
	}
}