#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>

using namespace std;
typedef long long ll;


ll ans, mx, mn, flag, sum, cnt;

int main(){
	string s;
	cin>>s;
	bool ok=true;
	for(ll i=0; i<s.size(); i++){
		if(i>=2 && i<s.size()-1 && s[i]=='C') cnt++;
		if(s[i]!='A' && s[i]!='C' && s[i]<96) ok=false;
	}
	if(s[0]=='A' && cnt==1 && ok==true) cout<<"AC";
	else cout<<"WA";
}