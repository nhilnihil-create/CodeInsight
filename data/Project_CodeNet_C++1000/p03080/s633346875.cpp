#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	int red = 0;
	int blue = 0;
	cin >> n >> s;
	for(int i=0;i<n;i++){
		if(s[i]=='R'){
			red++;
		} else {
			blue++;
		}
	}
	if(red>blue){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
