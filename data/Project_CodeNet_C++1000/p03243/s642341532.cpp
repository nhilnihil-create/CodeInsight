#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x = n / 111;
	int y = n % 111;

	cout << 111*(y==0?x:x+1) << endl;
	return 0;
}