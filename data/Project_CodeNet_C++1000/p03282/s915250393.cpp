#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	long long k;
	cin >> k;
	char ans='0';
	long double no=0;
	int i=0;
	long double index=0;
	while(true){
		no=s[i]-'0';
		index+=pow (no, 5*pow(10,15)-1);
		if(index>=k){
			ans=s[i];
			break;
		}else
			i++;
	}
	cout<<ans;
	return 0;
}