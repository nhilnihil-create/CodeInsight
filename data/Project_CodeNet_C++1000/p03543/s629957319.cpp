#include <iostream>

using namespace std;

int main(){
	char* n = (char*)calloc(5, sizeof(char));
	cin >> n;
	if(n[0] == n[1] && n[1] == n[2]) cout << "Yes";
	else if(n[1] == n[2] && n[2] == n[3]) cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
}
