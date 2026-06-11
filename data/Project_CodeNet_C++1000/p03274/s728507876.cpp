#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;

int main()
{
	int n,k;
	cin>>n>>k;
	k = k - 1;
	ll *x = new ll[n];
	rep(i,n){
		cin>>x[i];
	}
	ll left,right,distance;
	distance = 100000000000;
	for(int i = 0; i + k < n; i++){
		left = x[i];
		right = x[i+k];
		ll temp;
		if( left <= 0 && right <= 0){
			temp = abs(left);
		}else if(left >= 0 && right >= 0){
			temp = abs(right);
		}else{
			temp = min(abs(left),abs(right))*2 + max(abs(left),abs(right));
		}
		distance = min(distance,temp);
		//cout<<temp<<endl;
	}
	cout<<distance<<endl;
	return 0;
}

