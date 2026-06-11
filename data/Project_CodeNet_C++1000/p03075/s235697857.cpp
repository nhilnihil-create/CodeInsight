#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int a, b, c, d, e, k;
	cin >> a >> b >> c >> d >> e >> k;

	int max_pos = max({ a,b,c,d,e });
	int min_pos = min({ a,b,c,d,e });

	if (max_pos - min_pos <= k) {
		cout << "Yay!" << endl;
	}else{
		cout << ":(" << endl;
	}
}




