#include<iostream>
using namespace std;
int main(){
	char s[100010];
	int len = 0;
	int cnt = 1;
	cin >> s;
	while(s[len])len ++;
	if(len % 2 == 0){
		if(s[len / 2] != s[len / 2 - 1])cnt = 0;
		else{
			for(int i = 1; i < len / 2; i ++){
				if(s[len / 2 + i] == s[len / 2 - 1 - i] && s[len / 2 + i] == s[len / 2])cnt ++;
				else break;
			}
		}
		
	}else{
		for(int i = 1; i <= len / 2; i ++){
			if(s[len / 2] == s[len / 2 + i] && s[len / 2] == s[len / 2 - i])cnt ++;
			else break;
		}
	}
	cout << cnt + len / 2;
	return 0;
}