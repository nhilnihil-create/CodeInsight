#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++){
		int price = n - 7 * i;
		if(price >= 0 && price % 4 == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
