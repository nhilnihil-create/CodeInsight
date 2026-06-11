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

	int a, b, x;
	cin >> a >> b >> x;
	if ((a+b)>x&&x>=a)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

