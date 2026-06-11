#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string color;
	string kazu = "Three";
	for(int i=0; i<n; i++){
		cin >> color;
		if(color == "Y"){
			kazu = "Four";
		}
	}
	cout << kazu << endl;
}
