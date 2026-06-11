#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int  A,B;

	cin >> A >> B;

	if(A <= 8 && B <= 8){

		cout << "Yay!" << "\n";
	}
	else{
		 
		cout << ":(" << "\n"; 
	}
	return 0;
}
