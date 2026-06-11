//#include<bits/stdc++.h>
#include<iostream>
 
using namespace std;
 
typedef long long ll;
 
const int N = 200005;
 
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	
	s[k-1] = tolower(s[k-1]);
	
	cout<<s;
	
	return 0;
}
