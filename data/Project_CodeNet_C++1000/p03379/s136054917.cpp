#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define INF 1e17+9;
#define rep(i,n) for(int i=0;i<n;i++)

const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> x(n),temp(n);
	rep(i,n){
		cin >> x[i];
		temp[i]=x[i];
	}
	sort(temp.begin(),temp.end());
	map<int,long long> mp;
	rep(i,n){
		if(i<n/2)mp[temp[i]]=temp[n/2];
		else mp[temp[i]]=temp[n/2-1];
	}
	rep(i,n){
		cout << mp[x[i]] << endl;
	}
	return 0;
}

