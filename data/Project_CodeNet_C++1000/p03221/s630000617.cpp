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

struct city{
	int cityId;
	int group;
	int establishYear;
	int establishedOrder;
};

bool acs(struct city left,struct city right){
	if(left.group == right.group){
		if(left.establishYear < right.establishYear){
			return true;
		}else{
			return false;
		}
	}else if( left.group < right.group){
		return true;
	}else{
		return false;
	}
}

bool orderByCityId(struct city left,struct city right){
	if( left.cityId < right.cityId){
		return true;
	}else{
		return false;
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	struct city *cityList = new struct city[m];
	rep(i,m){
		cityList[i].cityId = i;
		int p,y;
		cin>>p>>y;
		cityList[i].group = p;
		cityList[i].establishYear = y;
	}
	sort(cityList,cityList + m,acs);	//group,year順
	int currentGroup = cityList[0].group;
	int counter = 1;
	rep(i,m){
		if(currentGroup != cityList[i].group){
			counter = 1;
			currentGroup = cityList[i].group;
		}
		cityList[i].establishedOrder = counter;
		counter++;
	}
	sort(cityList,cityList + m, orderByCityId);
	rep(i,m){
		printf("%06d%06d\n",cityList[i].group,cityList[i].establishedOrder);
	}
	return 0;
}

