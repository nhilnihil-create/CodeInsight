#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	long long x;
	cin >> x;
	if(x%10==x){
		cout << x << endl;
		return 0;
	}
	long long x_temp=x;
	bool all_9=true;
	int keta=0,now,now_sum=0;
	while(x_temp){
		keta++;
		now=x_temp%10;
		now_sum+=now;
		if(now!=9)all_9=false;
		x_temp/=10;
	}
	if(all_9==true){
		cout << 9*keta << endl;
		return 0;
	}
	long long ans=max(now_sum,9*(keta-1)+(now-1));
	cout << ans << endl;
	return 0;
}
