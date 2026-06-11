#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

int main(){	
	
	string s;
	cin >> s;
	if(s.size()%2!=0){
		reverse(s.begin(),s.end());
	}
	cout << s << endl;	
	
	return 0;
}
