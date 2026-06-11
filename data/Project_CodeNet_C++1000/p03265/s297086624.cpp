#include<iostream>
#include<cmath>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int dx = x2-x1; int dy = y2-y1;
	cout << x2-dy << " " << y2+dx << " " << x1-dy << " " << y1+dx;

	return 0;
}