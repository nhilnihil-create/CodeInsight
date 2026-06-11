#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;cin >>s;
	int win =8;
	int rday =15;
	int day =0;
	while(s.size()> day){
		auto f = s.substr(day,1);
		if(f=="o"){
			--win;
		}
		--rday;
		++day;
	}
	string ans;
	if(rday>=win){
		ans = "YES";
	} else {
		ans = "NO";	
	}
	cout << ans << endl;
	return 0;
}