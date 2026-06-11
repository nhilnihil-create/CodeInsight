#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	string key{"keyence"};
	if(s==key) {cout << "YES"; return 0;}
	for(int i=0;i<(int)s.length()-7;i++){
		for(int j = i;j < (int) s.length();j++){
			for(int k = 0;k<8;k++){
				//cout << s.substr(i,k)+s.substr(j,7-k) << endl;
				if(s.substr(i,k)+s.substr(j,7-k) == key){
					if(i>0 && j-i>k) continue;
					if(i==0 && j+7-k!=(int)s.length()) continue;
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	//zxlxbwhcvkpvoahiohfozjtceocbsgdnpnbpuyqejdbwgnapzeyence
}
