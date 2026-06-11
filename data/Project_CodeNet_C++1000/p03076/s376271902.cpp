#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
 


int main()
{
	//ifstream cin("input.txt");
	int n;
	int sum = 0;
	int mx = 0;
	rep(i,0,4){
		cin>>n;
		if(n%10 != 0){
			sum += n + (10 - n%10);
			mx = max(10 - n%10, mx);
		}
		else
			sum +=n;
		
	}
	cout<< sum - mx;
	
	

}