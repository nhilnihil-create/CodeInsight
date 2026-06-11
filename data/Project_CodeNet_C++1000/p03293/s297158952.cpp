#include<bits/stdc++.h>

using namespace std;

bool solve(string s1, string s2){
	if(s1.compare(s2)==0) return true;
	for(int i=0; i<s1.length(); i++){
		rotate(s1.begin(), s1.begin()+1, s1.end());
		if(s1.compare(s2)==0) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	if(solve(s1,s2)) cout << "Yes";
	else cout << "No";
	return 0;
}