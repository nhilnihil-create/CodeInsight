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

struct keyAndValue{
	int key;
	int value;
};

bool compKey(struct keyAndValue left,struct keyAndValue right){
	return (left.value < right.value);
}

int main()
{
	int n,k;
	cin>>n>>k;
	map<int,int> numMap;
	rep(i,n){
		int num;
		cin>>num;
		if(numMap.count(num) == 0){
			numMap.insert(make_pair(num,1));
		}else{
			numMap[num]++;
		}
	}
	vector<struct keyAndValue> vec;
	for(auto iter = numMap.begin(); iter != numMap.end(); iter++){
		struct keyAndValue temp;
		temp.key = iter->first;
		temp.value = iter->second;
		vec.push_back(temp);
		//cout<<temp.key<<" "<<temp.value<<endl;
	}
	sort(vec.begin(),vec.end(),compKey);
	int ans = 0;
	int diverse = vec.size() - k;
	diverse = max(diverse,0);
	rep(i,diverse){
		ans += vec[i].value;
	}
	cout<<ans<<endl;
	return 0;
}

