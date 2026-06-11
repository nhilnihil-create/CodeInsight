#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	long long a,b,c,k;
	cin >> a >> b >> c >> k;
	long long cnt=0,ans;
	if(k%2==1)ans=-a+b;
	else ans=a-b;
	if(ans>=1e18){
		cout << "unfair" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
