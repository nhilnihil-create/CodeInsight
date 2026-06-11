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

int main() {
	long long k,a,b;
	cin >> k >> a >> b;
	long long first_cost=a+2-1;
	long long bisk=1;
	
	if(first_cost>k || a+2>b){
		bisk+=k;
		cout << bisk << endl;
		return 0;
	}else{
		bisk=0;
		bisk+=b;
		k-=first_cost;
		if(k<0)k=0;
	}
	
	bisk+=(k/2)*(b-a);
	bisk+=k%2;
	cout << bisk << endl;
	return 0;
}

