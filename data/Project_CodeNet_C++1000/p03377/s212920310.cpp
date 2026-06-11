#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {

    ios::sync_with_stdio(false);
	
	int a, b, x;
	
	cin >> a >> b >> x;
	
	if (a > x || a+b < x){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}

    return 0;
}
