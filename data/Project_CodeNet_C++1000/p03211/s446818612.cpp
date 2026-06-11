#include<iostream>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char s[13];
	//char x;
	scanf("%s", s);
	int i;
	ll tmp, mint = INT_MAX;
	for(i=0; (i+2)<strlen(s); i++){
		tmp = (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0');
		mint = abs(tmp-753)<mint ? abs(tmp-753) : mint;
	}
	cout << mint << endl;
	return 0;
}
