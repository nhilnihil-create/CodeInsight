#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string s;

int main() {
	int cnt;
	cin>>s;
	for (int i=0;i<=s.size()-1;i++) {
		if (s[i]=='2') {
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;	
}