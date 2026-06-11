#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	string s[2];
	for(int i=0;i<2;i++){
		cin>>s[i];
	}
	if(s[0][0]==s[1][2] && s[0][1]==s[1][1] && s[0][2]==s[1][0]){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
