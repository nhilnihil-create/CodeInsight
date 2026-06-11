#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
int MOD = 1000000007;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k;
	vector<int> v(5);
	for(int i=0;i<5;i++){
		cin >> v.at(i);
	}
	cin >> k;
	bool flag = true;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<5;j++){
			if(v.at(j)-v.at(i) > k){
				flag = false;
			}
		}
	}
	if(flag) cout << "Yay!" << endl;
	else cout << ":(" << endl;

}	
