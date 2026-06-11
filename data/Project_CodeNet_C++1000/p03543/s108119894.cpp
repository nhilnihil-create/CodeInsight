#include <iostream>
using namespace std;

int main(){
	int n, sen, hyaku, juu, iti, count;
	cin >> n;
	sen = n / 1000;
	hyaku = (n - sen * 1000) / 100;
	juu = (n - sen * 1000 - hyaku * 100) / 10;
	iti = (n - sen * 1000 - hyaku * 100 - juu * 10) / 1;

	if (hyaku != juu)
		cout << "No" << endl;
	else if (hyaku == sen)
		cout << "Yes" << endl;
	else if (hyaku == iti)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}