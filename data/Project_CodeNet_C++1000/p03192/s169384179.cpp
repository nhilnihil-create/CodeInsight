#include "bits/stdc++.h"
using namespace std;
int main(){
	string S;
	cin  >> S;
	int count = 0;
	for(int x= 0 ;x<4;x++){
		if(S[x]=='2'){
			count++;
		}
	}
	cout << count;
	
}
