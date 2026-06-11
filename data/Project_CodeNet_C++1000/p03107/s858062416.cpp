#include<iostream>
#include<cstring>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int count0 = 0, count1 = 0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='0') count0++;
		else count1++;
	}
	cout << 2*min(count0, count1);
	return 0;
}