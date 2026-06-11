#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
	
	cout << 0 << endl;
	string current;
	cin >> current;

	if (current == "Vacant") {
		return 0;
	}
	
	int left=0, right=N, prev=0;;
	for(int i=0; i<20; i++) {
		int mid = (left+right)/2;
		
		// cout << "left " << left << " right " << right << " prev " << prev << " mid " << mid << endl;
		cout << mid << endl;
		string ans;
		cin >> ans;
		
		if (ans == "Vacant") return 0;
		else if (prev%2==mid%2) {
			if (prev < mid) {
				if (ans==current) left = mid;
				else right = mid;
			} else {
				if (ans==current) right = mid;
				else left = mid;
			}
		} else {
			if (prev < mid) {
				if (ans==current) right = mid;
				else left = mid;		
			} else {
				if (ans==current) left = mid;
				else right = mid;
			}

		}
		current = ans;
		prev = mid;
	}
  return 0;
}
