#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	string a="KIHBR...";
	int flag = 0;
	int x = 0;
	int ans = 1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A'){
			if(flag == 0){
				flag = 1;
			}else ans = 0;
		}else
		if(s[i] == a[x]){
			if(x == 0 || x == 1)flag = 1;
			else flag = 0;
			x++;
		}else
		ans = 0;
	}
	if(ans && x ==5)cout <<"YES"<<endl;
	else cout <<"NO"<<endl;
}
