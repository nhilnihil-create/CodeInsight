#include<bits/stdc++.h>
using namespace std;
void func(int n);
int ans[3] = {0};
int flg,sum;
string s;
int main(void){
	cin >> s;
	flg = 0;
	func(0);
	return 0;
}

void func(int n){
	//printf("n = %dsum = %dflg=%d\n",n,sum,flg);
	int i;
	if(flg == 0){
		if(n == 3){
			sum = s[0] - '0';
			for(i = 0; i < 3; i++){
				if(ans[i] == 1)	sum += s[i + 1] - '0';
				else			sum -= s[i + 1] - '0';
			}
			if(sum == 7){
				for(i = 0; i < 3; i++)	cout << s[i] << ((ans[i])?'+':'-');
				cout << s[3] << "=7" << endl;
				flg = 1;
			}
		}
		else{
			func(n + 1);
			ans[n] = 1;
			func(n + 1);
			ans[n] = 0;
		}
	}
}