#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
	string s;
	cin >> s;
	int i,n,a = 0,b = 0, c = 0;
	n = s.size();
	for(i=0;i<n;i++){
		if(s[i]=='a'){
			a++;
		}
		if(s[i]=='b'){
			b++;
		}
		if(s[i]=='c'){
			c++;
		}
	}
	int u = max({a,b,c}),v = min({a,b,c});
	if(u-v<=1){
		cout << "YES" << endl;
		return 0;
	}
	cout  << "NO" << endl;
}