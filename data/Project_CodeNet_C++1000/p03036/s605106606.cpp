#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int r, d ,x = 0;
	cin>>r>>d>>x;
	int resp = 0;
	
	for (int i=0; i<10;i++){
		
		resp=0;
		resp= r*x -d;
		x= resp;
		cout<<resp<< "\n";
		
	}
	return 0;
}