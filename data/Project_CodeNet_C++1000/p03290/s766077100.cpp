#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef unsigned long long int ll;

void printBit(int num){
	if(num == 0){
		cout<<0;
		return;
	}
	while(num > 0){
		if(num % 2 == 1){
			cout<<1;
		}else{
			cout<<0;
		}
		num /= 2;
	}
	return;
}

int main()
{
	int d,g;
	cin>>d>>g;
	vector<int> p(d);
	vector<int> c(d);
	rep(i,d) cin>>p[i]>>c[i];
	int ans = 1000;
	for(int bit = 0;bit < (1<<d); bit++){
		vector<int> tempP(d);
		int localSum = 0;
		int localCost = 0;
		for(int i = 0; i < d; i++){
			if( bit & (1<<i)){
				localCost += p[i];
				localSum += p[i] * (100*(i+1)) + c[i];
				tempP[i] = 0;
			}else{
				tempP[i] = max(0,p[i]-1);
			}
		}
		for(int i = d-1; i >= 0; i--){
			if( localSum >= g){
				ans = min(ans,localCost);
				break;
			}
			if( localSum + 100*(i+1)*tempP[i] >= g){
				for(int j = 0; j < tempP[i]; j++){
					localSum += (i+1)*100;
					localCost++;
					if(localSum >= g) break;
				}
				ans = min(ans,localCost);
				break;
			}else{
				localSum += tempP[i] * (100*(i+1));
				localCost += tempP[i];
			}
		}
		if(localSum >= g) ans = min(ans,localCost);
		//printBit(bit);
		//cout<<":"<<localSum<<","<<localCost<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
