#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
	string s;

	cin >> s;

	int id = 0, a = 0, b = 0, c = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'a')
			a++;
		else if (s[i] == 'b')
			b++;
		else
			c++;
	}

	if (s.size() == 1){
		cout << "YES";
	}
	else if (s.size() == 2){
		if (s[0] == s[1])
			cout << "NO";
		else
			cout << "YES";
	}
	else {
		if (abs(a-b) < 2 && abs(b-c) < 2 && abs(c-a) < 2)
			cout << "YES";
		else
			cout << "NO";
	}
	cout << endl;
}