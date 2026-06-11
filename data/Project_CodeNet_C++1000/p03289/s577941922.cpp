#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	bool AC=true;
	if (S[0]!='A') AC=false;
	int count=0;
	for (int i=2; i<S.length()-1; i++){
	    if (S[i]=='C') count++;
	}
	if (count!=1) AC=false;
	int COUNT=0;
	for (int i=0; i<S.length(); i++){
	    if (S[i]>='A' && S[i]<='Z') COUNT++;
	}
	if (COUNT!=2) AC=false;
	if (AC) cout << "AC" << endl;
	else cout << "WA" << endl;
}
