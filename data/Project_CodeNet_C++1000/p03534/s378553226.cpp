#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

string s;

int main(){
	int a = 0, b = 0, c = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'a')
			a++;
		if(s[i] == 'b')
			b++;
		if(s[i] == 'c')
			c++;
	}
	if(abs(a-b) > 1 || abs(a-c) > 1 || abs(b-c) > 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	
	return 0;
}