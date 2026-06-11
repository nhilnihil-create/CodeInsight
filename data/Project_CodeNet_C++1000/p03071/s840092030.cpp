#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	cout << (a==b?2*a:2*max(a,b)-1) << endl;

	return 0;
}