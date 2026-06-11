#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s[100];
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(i<50) s[i]+='#';
			else s[i]+='.';
		}
	}

	int a, b;
	cin >> a >> b;

	int x=0, y=0;
	for(int i=0; i<a-1; i++){
		s[x][y]='.';
		y+=2;
		if(y>=100){
			x+=2; y=0;
		}
	}
	x=51, y=0;
	for(int i=0; i<b-1; i++){
		s[x][y]='#';
		y+=2;
		if(y>=100){
			x+=2; y=0;
		}
	}

	cout << 100 << " " << 100 << endl;
	for(int i=0; i<100; i++) cout << s[i] << endl;

	return 0;
}