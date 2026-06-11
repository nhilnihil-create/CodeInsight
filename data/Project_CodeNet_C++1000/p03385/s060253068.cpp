#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	vector<int> c(s.size(),0);
	for(int i=0;i<s.size();i++){
		if(s[i]=='a')c[0]++;
		if(s[i]=='b')c[1]++;
		if(s[i]=='c')c[2]++;
	}
	if(c[0]==1 && c[1]==1 && c[2]==1)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
