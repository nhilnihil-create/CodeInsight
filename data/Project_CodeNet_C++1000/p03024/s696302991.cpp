#include <bits/stdc++.h>
using namespace std;

string s;
int n,win,lose,match;

int main(){
	cin>>s;
	n = s.length();
	for(int i = 0;i < n;i++){
		if (s[i] == 'o'){
			win++;
		}else{
			lose++;
		}
		match++;
	}
	if((8 - win) <= (15 - match)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
