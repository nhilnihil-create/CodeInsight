#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >>s;
	if(s.size() == 1){
		cout <<(s[0] - '0') <<"\n";
	}
	else{
		int cnt = 0, sum = 0;
		for(int i = 1; i < s.size(); ++i){
			if(s[i] == '9')
				++cnt;
		}
		if(cnt == s.size() - 1){
			sum = s[0] - '0' + cnt * 9;
		}
		else{
			sum = s[0] - '0' - 1 + (s.size() - 1) * 9;
		}
		cout <<sum <<"\n";
	}
	return 0;
}
