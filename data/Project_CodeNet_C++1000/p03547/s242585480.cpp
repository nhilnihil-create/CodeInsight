#include <bits/stdc++.h>
using namespace std;

int A = 10;
	int B = 11;
	int C = 12;
	int D = 13;
	int E = 14;
	int F = 15;

int main() {	
	
	char x,y; cin >>x>>y;
	int a,b;
	
	if (x=='A') a = 10;
	if (x=='B') a = 11;
	if (x=='C') a = 12;
	if (x=='D') a = 13;
	if (x=='E') a = 14;
	if (x=='F') a = 15;
	
	if (y=='A') b = 10;
	if (y=='B') b = 11;
	if (y=='C') b = 12;
	if (y=='D') b = 13;
	if (y=='E') b = 14;
	if (y=='F') b = 15;
	
	if (a < b) cout << "<";
	if (a > b) cout << ">";
	if (a == b) cout << "=";
   
   return 0;
}