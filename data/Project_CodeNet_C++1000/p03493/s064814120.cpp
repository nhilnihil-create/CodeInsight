#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	string s;
	cin >> s;
	int num  = 0;
	REP(i, 3){
		if(s[i] == '1')
			num++;
	}
	cout << num << endl;
}
