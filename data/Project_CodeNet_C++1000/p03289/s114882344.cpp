#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	string s;
	cin >> s;
	int len = s.size();
	if(s[0] != 'A'){
		cout << "WA" << endl;
		return 0;
	}
	int ccnt = 0;
	int cind;
	for(int i = 2;i <= len-2;i++){
		if(s[i] == 'C'){
			ccnt++;
			cind = i;
		}
	}
	if(ccnt != 1){
		cout << "WA" << endl;
		return 0;
	}
	for(int i = 1;i < len;i++){
		if(i == cind) continue;
		if(isupper(s[i])){
			cout << "WA" << endl;
			return 0;
		}
	}
	cout << "AC" << endl;
}