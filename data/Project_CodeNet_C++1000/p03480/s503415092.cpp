#include<iostream>
#include<string>
using namespace std;
string s;
int ans = 100010;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i = 1; i < (int)s.size(); ++i){
		if(s[i] != s[i - 1]){
			ans = min(ans, max(i, (int)s.size() - i));
		}
	}
	cout << min(ans, (int)s.size()) << '\n';
	return 0;
}
