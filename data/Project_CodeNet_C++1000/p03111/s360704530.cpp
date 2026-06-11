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

int main()
{
	int n;
	int a[3];
	cin>>n>>a[0]>>a[1]>>a[2];
	vector<int> l(n);
	rep(i,n) cin>>l[i];
	int ans = 80 + 1000*3;
	for(int bit = 0; bit < pow((double)4,(double)n);bit++){
		int counter = bit;
		vector<vector<int>> numList(3);
		int cost = 0;
		for(int i = 0; i < n; i++){
			if( counter % 4 == 0){
				numList[0].push_back(l[i]);
			}else if( counter % 4 == 1){
				numList[1].push_back(l[i]);
			}else if( counter % 4 == 2){
				numList[2].push_back(l[i]);
			}else{
				//do nothing
			}
			counter /= 4;
		}
		/*for(int i = 0; i < 3; i++){
			cout<<"i th"<<endl;
			for(auto iter = numList[i].begin(); iter != numList[i].end(); iter++){
				cout<<*iter<<" ";
			}
			cout<<endl;
		}*/
		if( numList[0].size() == 0 || numList[1].size() == 0 || numList[2].size() == 0){
			
		}else{
			for(int i = 0; i < 3; i++){
				cost += (numList[i].size()-1)*10;
				int length = 0;
				for(auto iter = numList[i].begin();iter != numList[i].end(); iter++){
					length += *iter;
				}
				cost += abs(a[i] - length);
			}
			//cout<<cost<<endl;
			ans = min(ans,cost);
		}
	}
	cout<<ans<<endl;
	return 0;
}
