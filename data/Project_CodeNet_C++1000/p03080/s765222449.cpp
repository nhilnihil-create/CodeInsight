#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int cnt_r=0,cnt_b=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R')cnt_r++;	
		if(s[i]=='B')cnt_b++;	
	}
	if(cnt_r > cnt_b){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
