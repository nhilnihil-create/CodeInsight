#include<iostream>
#include<string>
using namespace std;
 
int main(){
	string s, e, ans = "NO";

	cin >> s;

	//高々100文字なので、文字列の抜き出し方（消し方）を全て網羅する
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j <= s.size() - i; j++){
			e = s;	//erase()すると文字列が変わっちゃうので、元々の文字列を別の変数にコピーした方をいじくる
			if(e.erase(i,j) == "keyence") {	//erase(n, m):文字列のn文字目からn文字消す
				ans = "YES";
			}
		}
	}
 
	cout << ans << endl;
}