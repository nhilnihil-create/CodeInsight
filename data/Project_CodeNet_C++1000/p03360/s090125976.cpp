#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {

    ios::sync_with_stdio(false);
	
	int a, b, c, k, maior;
	
	cin >> a >> b >> c;
	cin >> k;
	
	maior = max(max(a, b), c);
	
	for(int i = 0; i < k; i++){
		maior = maior*2;
	}
	
	cout << a + b + c - max(max(a, b), c) + maior << endl;

    return 0;
}
