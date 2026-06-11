#include<bits/stdc++.h>
using namespace std;
int n , k;
string s;
char z(char ch){
	if(ch=='A') return 'a';
	if(ch=='B') return 'b';
	if(ch=='C') return 'c';
}
int main(){
	cin >> n >> k >> s;
	s[k-1]=z(s[k-1]);
	cout<<s<<'\n';
	return 0;
}