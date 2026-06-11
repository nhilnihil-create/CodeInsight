#include <bits/stdc++.h>
using namespace std;

int cntChar(bool cntX[], bool cntY[]){
	int sum = 0;
	for(int i=0;i<26;i++){
		sum = (cntX[i] && cntY[i]) ? sum+1 : sum;
	}
	return sum;
}

void count(bool cnt[], string s){
	int i=0;
	while(s[i]){
		cnt[s[i]- 'a'] = 1;
		i++;
	}
}

int cutAndCount(string s, int n){
	string x, y;
	bool cntX[26], cntY[26];
	int max = 0;
	for(int i = 0; i < (n-1); i++){
		for(int j=0;j<26;j++){
			cntX[j] = 0; cntY[j] = 0;
		}
		x = s.substr(0, i+1);
		y = s.substr(i+1, n-i-1);
		count(cntX, x);
		count(cntY, y);
		int tmp = cntChar(cntX, cntY);
		max = (tmp > max) ? tmp : max;
	}
	return max;
}


int main(){
	int n;
	string s;
	cin >> n;
	cin.ignore();
	getline(cin, s,'\n');
	cout << cutAndCount(s, n);
}