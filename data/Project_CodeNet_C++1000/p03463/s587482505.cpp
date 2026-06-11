#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int s = abs(a-b);
	if(s%2 == 1) cout << "Borys" << endl;
	if(s%2 == 0) cout << "Alice" <<endl;
}
