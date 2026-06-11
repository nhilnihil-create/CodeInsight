#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	string S; 
	cin >> S; 
	int L = S.size(); 
	char C = S.at(L/2); 
	int hatan = 0; 
	if(L % 2 == 0){
		for(int i = 0; i < L / 2; i++){
			if(S.at(L / 2 - 1 - i) != C || S.at(L / 2 + i) != C){break;}
			hatan ++; 
		}
	}
	else if(L % 2 == 1){
		for(int i = 0; i <= L / 2; i++){
			if(S.at(L / 2 - i) != C || S.at(L / 2 + i) != C){break;}
			hatan ++; 
		}
	}
	cout << L/2 + hatan << endl; 
}