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

struct node{
	int num;
	int count;
};

bool comp(const node LHS,const node RHS){
	return LHS.count > RHS.count;
}

int main()
{
	int n;
	cin>>n;
	vector<node> evenVec(100001);
	vector<node> oddVec(100001);
	for(int i = 0 ; i < 100001; i++){
		evenVec[i].count = 0;
		evenVec[i].num = i;

		oddVec[i].count = 0;
		oddVec[i].num = i;
	}
	for(int i = 0; i < n; i++){
		int num;
		cin>>num;
		if( i % 2 == 0){
			evenVec[num].count++;
		}else{
			oddVec[num].count++;
		}
	}
	sort(evenVec.begin(),evenVec.end(),comp);
	sort(oddVec.begin(),oddVec.end(),comp);
	ll ans = 0;
	if( evenVec[0].num != oddVec[0].num){
		ans = n - (evenVec[0].count + oddVec[0].count);
	}else{
		int pattern1 = n - (evenVec[0].count + oddVec[1].count);
		int pattern2 = n - (evenVec[1].count + oddVec[0].count);
		ans = min(pattern1,pattern2);
	}
	cout<<ans<<endl;

	return 0;
}
