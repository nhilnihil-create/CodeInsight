#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	if (A <= C && C <= B) {
		cout << "Yes" << endl;
	}
	else if(B<=C&&C<=A){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
