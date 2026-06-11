#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int ans=0,cnt=0;

	for(int i=0; i<s.size(); i++){
		if(s.at(i)=='A'||s.at(i)=='T'||s.at(i)=='C'||s.at(i)=='G'){
			cnt++;
			if(ans < cnt) ans = cnt;
		}
		else cnt = 0;
	}

	cout << ans << endl;

	return 0;
}