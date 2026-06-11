#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	if(s[0] != 'A'){
		cout << "WA";
		return 0;
	}
	int count_c = 0;
	for(int i=2; i<s.length()-1; i++){
		if(s[i]=='C'){
			count_c++;
		}
	}
	if(count_c != 1){
		cout << "WA";
		return 0;
	}
	string strcopy = s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
    
	for(int i=1; i<s.length(); i++){
		if(strcopy[i]=='C') continue;
		else{
			if(strcopy[i] != s[i]){
				cout << "WA";
				return 0;
			}
		}
	}
	cout << "AC";
	return 0;
}