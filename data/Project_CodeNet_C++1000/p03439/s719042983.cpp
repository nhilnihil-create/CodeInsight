#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin >> n;
	int x = 0, y = n - 1;
	string a, b;
	cout << x << endl;
	cin >> a;
	if( a == "Vacant")	
		return 0;
	cout << y << endl;
	cin >> b;
	if( b == "Vacant")
		return 0;
	int m = (x + y)/2;
	cout << m << endl;
	string c;
	cin >> c;
	if( c == "Vacant")
		return 0;
	if( c == a && (abs(x - m) - 1) % 2 == 0)
		y = m, b = c;
	else if( c == b &&  (abs(x - m) - 1) % 2 == 0)
		x = m , a = c;
	else if( c != a && (abs(x - m) - 1) % 2 == 1)
		y = m, b = c;
	else
		x = m, a = c;
	while( true ){
		m = (x + y)/2;
		cout << m << endl;
		cin >> c;
		if( c == "Vacant")
			return 0;
		if( c == a && (abs(x - m) - 1) % 2 == 0)
			y = m, b = c;
		else if( c == b &&  (abs(x - m) - 1) % 2 == 0)
			x = m , a = c;
		else if( c != a && (abs(x - m) - 1) % 2 == 1)
			y = m, b = c;
		else
			x = m, a = c;
	}
    return 0;
}