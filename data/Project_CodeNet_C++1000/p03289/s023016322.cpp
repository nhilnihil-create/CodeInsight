/*
Author : Devil088
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define sep cout<<"\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

inline string shift(string s){
	int n = s.length();
	string r = "";
	r+=s[n-1];
	for(int i=0;i<n-1;i++)r+=s[i];
	return r;
}

int main(){
	string s;
	cin>>s;
	int n = s.length();
	if(s[0]!='A')cout<<"WA\n";
	else{
		bool flag = true;
		bool c = false;
		if(s[1]=='C' || s[1]<97){
			flag = false;
		}
		for(int i=2;i<n-1;i++){
				if(s[i]<97 && s[i]!='C'){
					flag = false;
					break;
				}
				if(s[i] == 'C'){
					if(c == false)c = true;
					else {
						flag = false;
						break;
					}
				}
		}
		if(s[n-1]<97)flag = false;
		if(flag && c)cout<<"AC\n";
		else cout<<"WA\n";
	}
}
/*
uday
adyu
7 46
45 6
*/

