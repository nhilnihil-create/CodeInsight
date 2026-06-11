#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,k;
	// nyuryoku
	string s;
	cin >> n >> k >> s;
	k--;
	// keisan
	char c = s[k];
	s[k] = 'a' + c - 'A';
	// syutsuryoku
	cout << s << endl;
}