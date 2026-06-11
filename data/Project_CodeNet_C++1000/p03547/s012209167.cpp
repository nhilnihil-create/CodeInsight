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
	
	char x, y;
	cin >> x >> y;
	if (x > y)
		cout << ">" << endl;
	else if (x < y)
		cout << "<" << endl;
	else
		cout << "=" << endl;

}

