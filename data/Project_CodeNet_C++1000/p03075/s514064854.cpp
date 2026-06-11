#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a;
	for(int i = 0; i< 6; i++){
		int input;
		cin >> input;
		a.push_back(input);
	}
	for(int i =0; i < a.size() - 1; i++){
		for(int j = 0; j < a.size() - 1; j++){
			if(abs(a[i] - a[j]) > a[5]){
				cout << ":(" << endl;
				return 0;
			}
		}
	}
	cout << "Yay!" << endl;


	return 0;
}
