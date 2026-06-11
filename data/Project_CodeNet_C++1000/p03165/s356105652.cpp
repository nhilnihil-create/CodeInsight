#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s,t;
	cin>>s>>t;
	
	int memo[s.length()+1][t.length()+1];
	
	for(int i=0; i<=s.length(); i++) {
		for(int j=0; j<=t.length(); j++) {
			if(i==0 || j==0) {
				memo[i][j] = 0;
			} else if(s[i-1] == t[j-1]) {
				memo[i][j] = 1+memo[i-1][j-1];
			} else {
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
			}
		}
	}
	
	int index = memo[s.length()][t.length()];
	char lcs[index+1];
	lcs[index] = '\0';
	
	int i=s.length();
	int j=t.length();
	while(i>0 && j>0) {
		if(s[i-1] == t[j-1]) {
			lcs[index-1] = s[i-1];
			i--;
			j--;
			index--;
		} else if(memo[i-1][j] > memo[i][j-1]) {
			i--;
		} else {
			j--;
		}
	}
	
	cout<<lcs;
	
	return 0;
}