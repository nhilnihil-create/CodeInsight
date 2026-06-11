#include <bits/stdc++.h>
using namespace std;

int main() {
	int k,ans=0;
	string s;
	cin >> s;
	k=s.size();
	for(int i=0; i<k; i++){
		if(s[i]=='x') ans++;
	}
	if(ans>7){
		cout << "NO";
	}else{
		cout << "YES";
	}
}
