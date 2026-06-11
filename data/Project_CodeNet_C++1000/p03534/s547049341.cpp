#include<bits/stdc++.h>
using namespace std;

int k[3];
signed main(){
	string a;cin>>a;
	for(char i:a){
		k[i-'a']++;
		}
	sort(k,k+3);
	if(k[2]-k[0]<=1)puts("YES");
	else puts("NO");	
	}
