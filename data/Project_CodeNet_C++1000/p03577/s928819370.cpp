#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(void){
	string s;
	cin >> s;
	for(int i=0;i<s.length()-8;i++){
		cout << s.at(i) ;
	}
	cout << endl;
	return 0;
}