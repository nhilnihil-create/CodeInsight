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

	int a, b;
	cin >> a >> b;
	if (a <= 8 && b <= 8 && (a + b) <= 16)
		cout << "Yay!" << endl;
	else
		cout << ":(" << endl;
}

