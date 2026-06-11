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

long long n;
long long ans=0;

void check(long long x){
	string s=to_string(x);
	int c3,c5,c7;
	c3=c5=c7=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='3'){
			c3++;
		}else if(s[i]=='5'){
			c5++;
		}else if(s[i]=='7'){
			c7++;
		}
	}
	if(c3>0 && c5>0 && c7>0){
		ans++;
	}
}

void dfs(long long x){
	if(x<=n){
		check(x);
	}
	if(x<=1000000000){
		dfs(10*x+3);
		dfs(10*x+5);
		dfs(10*x+7);
	}else{
		//cout << x << endl;
	}
}

int main(){
	cin >> n;
	dfs(0);
	cout << ans << endl;
	return 0;
}
