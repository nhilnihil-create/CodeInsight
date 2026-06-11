#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
  	string S;
  	string result = "Three";
  	cin >> N;
  
  	for(int i = 1; i <= N; i++) {
    	cin >> S;
      	if(S == "Y") {
        	result = "Four";
        }
    }
  
  	cout << result << endl;  	
}