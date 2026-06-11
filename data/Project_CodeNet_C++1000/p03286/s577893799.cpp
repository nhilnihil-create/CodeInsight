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
typedef long long int ll;

void printBit(ll num){
	if( num == 0){
		cout<<0<<endl;
		return ;
	}
	stack<int> ans;
	while(num > 0){
		if( num % 2 == 1){
			ans.push(1);
		}else{
			ans.push(0);
		}
		num /= 2;
	}
	while(!ans.empty()){
		cout<<ans.top();
		ans.pop();
	}
	cout<<endl;
	return;
}

int main()
{
	int n;
	cin>>n;
	if( n == 0){
		cout<<0<<endl;
		return 0;
	}
	stack<int> ans;
	while( n != 0){
		if( abs(n - 1) % 2 == 0){
			ans.push(1);
			n = (n-1)/(-2);
		}else{
			ans.push(0);
			n = n / (-2);
		}
	}
	while( ! ans.empty()){
		cout<<ans.top();
		ans.pop();
	}
	cout<<endl;
	return 0;
}
