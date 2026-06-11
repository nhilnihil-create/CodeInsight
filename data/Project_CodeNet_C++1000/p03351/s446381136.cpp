#include <iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<queue>
#include<set>
#include<string>
using namespace std;
void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main()
{
	fast();

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (abs(a - b) <= d && abs(b - c) <= d)
		cout << "Yes" << endl;
	else if(abs(a - c) <= d)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

