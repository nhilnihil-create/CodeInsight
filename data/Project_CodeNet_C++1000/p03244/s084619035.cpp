#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	map<int,int> mp1;
	map<int,int> mp2;
	for(int i = 0;i < n;i++){
		int v;
		cin >> v;
		if(i % 2 == 0)mp1[v]++;
		else mp2[v]++;
	}

	int mx11 = 0,mx11_value = 0;
	for(auto p:mp1){
		if(p.second > mx11){
			mx11 = p.second;
			mx11_value = p.first;
		}
	}

	int mx12 = 0,mx12_value = 0;
	for(auto p:mp1){
		if(p.second > mx12 && p.first != mx11_value){
			mx12 = p.second;
			mx12_value = p.first;
		}
	}

	int mx21 = 0,mx21_value = 0;
	for(auto p:mp2){
		if(p.second > mx21){
			mx21 = p.second;
			mx21_value = p.first;
		}
	}

	int mx22 = 0,mx22_value = 0;
	for(auto p:mp2){
		if(p.second > mx22 && p.first != mx21_value){
			mx22 = p.second;
			mx22_value = p.first;
		}
	}

	/*
	printf("%d:%d\n",mx11,mx11_value);
	printf("%d:%d\n",mx12,mx12_value);
	printf("%d:%d\n",mx21,mx21_value);
	printf("%d:%d\n",mx22,mx22_value);
	*/

	int ans = n;
	if(mx11_value != mx21_value){
		ans = min(ans,n-mx11-mx21);
	}
	if(mx11_value != mx22_value){
		ans = min(ans,n-mx11-mx22);
	}
	if(mx12_value != mx21_value){
		ans = min(ans,n-mx12-mx21);
	}
	if(mx12_value != mx22_value){
		ans = min(ans,n-mx12-mx22);
	}

	cout << ans << endl;
}
