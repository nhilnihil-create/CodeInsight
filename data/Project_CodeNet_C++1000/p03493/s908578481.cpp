#include <bits/stdc++.h>
using namespace std;

int main() {
	string A;
  	cin >> A;
    int count = 0;
  	for (int i=0; i<3; i++){
    	if (A[i]=='1') count++;
    }
    cout << count << endl;
}	
