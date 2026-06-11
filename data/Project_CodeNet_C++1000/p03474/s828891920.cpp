#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	string s;
	cin >> a >> b;
	cin >> s;
	for (int i=0; i<s.length(); i++){
		if (i==a){
			if (s[i]!='-'){
				printf("No\n");
				return 0;
			}
		}
		else if (s[i]<'0' || s[i]>'9'){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}