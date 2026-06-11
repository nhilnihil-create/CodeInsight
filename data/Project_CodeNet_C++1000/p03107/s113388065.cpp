#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a,b,c;
int tot;
string s;
int main(){
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] == '0') a++;
		else b++;
	}
	cout << min(a,b)*2;
}
 