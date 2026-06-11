#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum = 0;
	string k;
	cin >> k;
	for(int i = 0; i < k.length(); i++){
		if(k[i] == '+')
			sum++;
		else
			sum--;
	}
	cout << sum << endl;

	return 0;
}