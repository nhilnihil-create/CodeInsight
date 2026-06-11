#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	string s;
	cin >> s;
	string t="FESTIVAL";
	for(int i=0;i<s.size()-t.size();i++){
		cout << s[i];
	}
	cout << endl;
	return 0;
}
