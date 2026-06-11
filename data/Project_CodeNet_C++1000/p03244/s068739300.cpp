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

struct myMap{
	int index;
	int times;
};

bool desc(struct myMap left,struct myMap right){
	return left.times > right.times;
}

int main()
{
	map<int,int> oddArrayCount;
	map<int,int> evenArrayCount;
	int n;
	cin>>n;
	int *v = new int[n];
	rep(i,n){
		cin>>v[i];
	}
	for(int i = 0;i < n; i++){
		if( i % 2 == 0){
			if( evenArrayCount.count(v[i]) == 0){
				evenArrayCount.insert(make_pair(v[i],1));
			}else{
				evenArrayCount[v[i]]++;
			}
		}else{
			if( oddArrayCount.count(v[i]) == 0){
				oddArrayCount.insert(make_pair(v[i],1));
			}else{
				oddArrayCount[v[i]]++;
			}
		}
	}
	struct myMap *oddArrayHistgram = new myMap[oddArrayCount.size()];
	int index = 0;
	for(auto iter = oddArrayCount.begin(); iter != oddArrayCount.end(); iter++){
		oddArrayHistgram[index].index = iter->first;
		oddArrayHistgram[index].times = iter->second;
		index++;
	}
	struct myMap *evenArrayHistgram = new myMap[evenArrayCount.size()];
	index = 0;
	for(auto iter = evenArrayCount.begin(); iter != evenArrayCount.end(); iter++){
		evenArrayHistgram[index].index = iter->first;
		evenArrayHistgram[index].times = iter->second;
		index++;
	}
	sort(oddArrayHistgram,oddArrayHistgram + oddArrayCount.size(),desc);
	sort(evenArrayHistgram,evenArrayHistgram + evenArrayCount.size(),desc);

	int ans;
	if( oddArrayHistgram[0].index != evenArrayHistgram[0].index){
		ans = n - (oddArrayHistgram[0].times + evenArrayHistgram[0].times);
	}else if(oddArrayCount.size() == 1 && evenArrayCount.size()){ //全部同じの場合
		ans = n / 2;
	}else{
		int numOdd,numEven;
		if(oddArrayCount.size() == 1){
			numOdd = n / 2;
		}else{
			numOdd = oddArrayHistgram[1].times;
		}
		if(evenArrayCount.size() == 1){
			numEven = n / 2;
		}else{
			numEven = evenArrayHistgram[1].times;
		}

		if( numEven >= numOdd){
			ans = n - (numEven + oddArrayHistgram[0].times);
		}else{
			ans = n - (numOdd + evenArrayHistgram[0].times);
		}
	}
	cout<<ans<<endl;
	return 0;
}

