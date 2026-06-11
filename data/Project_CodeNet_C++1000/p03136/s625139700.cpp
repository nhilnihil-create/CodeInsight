#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> l(n);
	
	for(int i = 0; i < n; i++){
		cin >> l.at(i);
	}
	
	sort(l.begin(), l.end());
	
	bool ans_flg = true;
	
	int others = 0;
	for(int i = 0; i < n-1; i++){
		others += l.at(i);
	}
	ans_flg = (l.at(n-1) < others) ? true : false;
	
	string ans = ans_flg ? "Yes" : "No";
	
	cout << ans << endl;
	
}