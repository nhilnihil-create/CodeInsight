#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {

    ios::sync_with_stdio(false);
	
	int a, b, soma, menos, vzs;
	
	cin >> a >> b;
	
	soma = a+b;
	menos = a-b;
	vzs = a*b;
	
	cout << max(max(soma, menos), vzs) << endl;

    return 0;
}
