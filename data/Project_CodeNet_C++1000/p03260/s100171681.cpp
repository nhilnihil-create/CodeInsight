#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {

    ios::sync_with_stdio(false);
	
	int a, b;
	
	cin >> a >> b;
	
	if (a%2 == 0 || b%2 == 0){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}

    return 0;
}
