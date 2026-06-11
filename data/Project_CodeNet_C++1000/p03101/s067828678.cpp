#include <bits/stdc++.h>
using namespace std;


int main(){
	int R, C, r, c;
	cin >> R>> C>> r>> c;
	int blackSq =0;
	blackSq+= r*C;
	blackSq +=  c* (R-r);
	int whiteSq= (R*C)- blackSq;
	cout << whiteSq<< '\n'; 
}