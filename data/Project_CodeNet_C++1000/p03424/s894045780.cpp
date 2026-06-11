#include <bits/stdc++.h>
using namespace std;

int main() {

	int N;
	cin >> N;
	
	int P,W,G,Y;
	P = 0;
	W = 0;
	G = 0;
	Y = 0;
	
	for(int i = 0;i < N; i++){
		string S;
		cin >> S;
		
		if (S == "P") {
      		P = 1;
    	}else if (S == "W") {
      		W = 1;
      	}else if (S == "G") {
      		G = 1;
      	}else if (S == "Y") {
      		Y = 1;
      	}
    }
    if (3 == P + W + G + Y){
    	cout << "Three";
    }else if (4 == P + W + G + Y){
    	cout << "Four";
    }
}
