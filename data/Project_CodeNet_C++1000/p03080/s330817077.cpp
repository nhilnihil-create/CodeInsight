#include <iostream>
using namespace std;

int main(){
	int n = 4;
	cin >> n;
	char s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	
	int redCnt = 0;
	int blueCnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R') redCnt++;
		else blueCnt++;
	}
	if(redCnt > blueCnt) cout << "Yes";
	else cout << "No";
	return 0;
}