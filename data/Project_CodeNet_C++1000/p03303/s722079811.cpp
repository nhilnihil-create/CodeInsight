#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	string s;
	int w;
	cin >> s >> w;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(cnt>w-1)cnt=0;
		if(cnt==0)cout << s[i];
		cnt++;
	}
	return 0;
}
