#include<bits/stdc++.h>
using namespace std;

int a, b, luas;

int main () {
	cin>> a >> b >> luas;
	luas=(a*b - ((a*1) + (b*1)-1));
	cout<< luas << endl;
}