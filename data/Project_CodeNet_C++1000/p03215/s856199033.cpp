//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int N;
long long int a[1000];
long long int K;
long long int ans = 0;

vector<long long int> list;

void solve(){
	for(int i=0;i<N;i++){//a[i]を始点として
		for(int j=i;j<N;j++){//a[j]までを足し合わせる(a[j]含む)
			long long int sum = 0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			list.push_back(sum);
		}
	}
	sort(list.begin(),list.end(),greater<long long int>());

	if(list[list.size()-1]==0 && list.size()<=K) return;

	for(int i=63;i>=0;i--){
		vector<long long int> new_list;
		for(int j=0;j<list.size();j++){
			if((list[j]>>i)&1ll){
				new_list.push_back(list[j]);
			}
		}
		if(new_list.size()>=K){
			list = new_list;
			if(new_list.size()==K) break;
		}
	}
	ans = ~ans;
	for(int j=0;j<list.size();j++){
		ans&=list[j];
	}
}

int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++) cin >> a[i];

	solve();

	cout << ans;
	return 0;
}
