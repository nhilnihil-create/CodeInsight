#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, i;
	cin>>a>>b;
	string s;
	getline(cin, s);
	getline(cin, s);

	if(s.at(a)!='-'){
		cout << "No" << endl;
		return 0;
	}
	
	for(i=0;i<a+b-1;i++){
		if(i==a)continue;
		if(s.at(i)<'0' || s.at(i)>'9'){
			cout << "No" << endl;
			return 0;
		}
		//cout << "hello" << endl;
	}

	cout << "Yes" << endl;
}