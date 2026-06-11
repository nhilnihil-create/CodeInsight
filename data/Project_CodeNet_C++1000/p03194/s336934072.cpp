#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

long long a , b , ans;

long long check(long long x){
	long long now = 1;
	for(int i = 1; i <= a ; i++){
		now *= x;
		if(now > b)return 0;
	}

	return (b % now) + 1;
}

int main(){
	cin >> a >> b;
	if(a == 1){
		cout << b;
		return 0;
	}
	long long now;
	long long i = 1;
	ans = 1;
	for(i = 2 ; i <= b ; i++){
		now = check(i);
		if(now == 0)break;
		if(now == 1){
			ans = max(ans,i);
		}
	}
	 cout << ans << endl ;
}