#include<iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n=s.length();
	int t=s.length();
	for(int i=0;i<n-1;i++){
		if(s[i]!=s[i+1]) {
			t=min(t,max(i+1,n-(i+1)));
		}
	}
	cout << t << endl;
}
