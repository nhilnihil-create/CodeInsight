#include<iostream>

using namespace std;

int main()
{
	int n;
	bool can = false;

	cin >> n;

	for(int i=0; i<=n/4; i++){
		for(int j=0; j<=n/7; j++){
			if((4 * i) + ( 7 * j) == n)
				can = true;
		}	
	}
		if(!can)
			cout << "No" << endl;
		else 
			cout << "Yes" << endl;
	}
