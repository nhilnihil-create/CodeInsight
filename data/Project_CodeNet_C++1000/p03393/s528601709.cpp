#include<bits/stdc++.h>
using namespace std;

string s;
int n, pos;
bool vis[27];

int main() {
	cin>>s;
	n = s.size();
	if(s == "zyxwvutsrqponmlkjihgfedcba") {
		cout<<-1<<endl;
		return 0;
	}
	if(n < 26) {
		for(int i = 0; i < n; i++)
			vis[s[i] - 'a' + 1] = 1;
		cout<<s;
		for(int i = 1; i <= 26; i++) 
			if(!vis[i]) {
				cout<<(char) (i + 'a' - 1)<<endl;
				return 0;
			}
	}
	for(int i = 25; i >= 0; i--) {
		vis[s[i] - 'a' + 1] = 1;
		for(int j = s[i] - 'a' + 2; j <= 26; j++)
			if(vis[j]) {
				for(int k = 0; k < i; k++)
					cout<<s[k];
				cout<<(char) (j + 'a' - 1)<<endl;
				return 0;
			}
	}
	return 0;
}