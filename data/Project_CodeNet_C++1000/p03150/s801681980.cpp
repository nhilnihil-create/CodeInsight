#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, leftstr, rightstr;

int main(){
	cin >> s;
	int n = s.size();

	for(int i=0; i<7; i++){
		leftstr = s.substr(0, i);
		rightstr = s.substr(i+n-7);

		if(leftstr + rightstr == "keyence"){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
	return 0;
}