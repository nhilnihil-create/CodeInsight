#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	char b; cin>>b;
	if(b=='A'||b=='T') cout<<(char)(b^'A'^'T')<<endl;
	else cout <<(char)(b^'G'^'C')<<endl;
}