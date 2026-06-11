#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin>>s;
	long long int maxl=0;
	long long int cl=0;
	for(long long int i=0;i<s.size();i++){
		if((s[i]=='A'||s[i]=='T'||s[i]=='C'||s[i]=='G')){
			cl++;
			maxl=max(maxl,cl);
		}
		else{
			cl=0;
		}
	}
	cout<<maxl;
	return 0;
}