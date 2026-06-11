#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();
	
	string n;
	cin >> n;

	if ((n[0] == n[1] && n[1] == n[2]) || (n[0] == n[1] && n[1] == n[2] && n[2] == n[3]) || (n[1] == n[2] && n[2] == n[3]) )
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}