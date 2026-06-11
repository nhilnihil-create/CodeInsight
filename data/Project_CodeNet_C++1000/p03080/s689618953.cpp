#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;cin >>n;
	string s;cin >> s;
	int cnt = 0;
	for(int i=0;i<n;++i){
		auto sub = s.substr(i,1);
		if(sub=="R"){
			++cnt;
		} else {
			--cnt;
		}
	}
	if(cnt>0){
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}