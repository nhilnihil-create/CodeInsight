#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s; cin >> s;
	int N = atoi(s.c_str());
	int l = 0;
	for(int i=0; i<s.size(); i++){
		char c[2] = {0};
		c[0] = s[i];
		l += atoi(c);
	}
	if(N % l == 0){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
