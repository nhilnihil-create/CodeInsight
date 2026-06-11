#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int count[3]={0,0,0};
	for(int i=0; i<(int)s.length(); i++){
		count[s[i]-'a']++;
	}
	int cmax=0, cmin=1e9;
	for(int i=0; i<3; i++){
		cmax=max(cmax, count[i]);
		cmin=min(cmin, count[i]);
	}
	if(cmax-cmin>1){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
	}
	return 0;
}