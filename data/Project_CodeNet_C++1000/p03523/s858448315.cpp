#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	if ("KIHBR" == S) cout << "YES";
	else if ("AKIHBR" == S) cout << "YES";
	else if ("KIHABR" == S) cout << "YES";
	else if ("KIHBAR" == S) cout << "YES";
	else if ("KIHBRA" == S) cout << "YES";
	else if ("AKIHABR" == S) cout << "YES";
	else if ("AKIHBAR" == S) cout << "YES";
	else if ("AKIHBRA" == S) cout << "YES";
	else if ("KIHABAR" == S) cout << "YES";
	else if ("KIHABRA" == S) cout << "YES";
	else if ("KIHBARA" == S) cout << "YES";
	else if ("AKIHABAR" == S) cout << "YES";
	else if ("AKIHABRA" == S) cout << "YES";
	else if ("AKIHBARA" == S) cout << "YES";
	else if ("KIHABARA" == S) cout << "YES";
	else if ("AKIHABARA" == S) cout << "YES";
	else cout << "NO";
}