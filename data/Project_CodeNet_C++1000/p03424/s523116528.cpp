#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N;
	string S;
	string mes;
  
	int i;
	i = 0;
	cin >> N;
 
while (i <= N){
	cin >> S;
	if ( S == "Y" ){
		mes = "Four";
		break;
	}else{
		mes = "Three";
	}
  i++;
}
  	cout << mes;
}
