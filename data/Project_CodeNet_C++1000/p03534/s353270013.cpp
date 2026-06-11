#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int num[3];
	for(int i = 0; i < 3; i++) num[i] = 0;
	for(int i = 0; i < s.size(); i++){
		num[s[i] - 'a']++;
	}
	if(abs(num[0] - num[1]) <= 1 && abs(num[1] - num[2]) <= 1 && abs(num[2] - num[0]) <= 1){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}