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
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

//xを素因数分解する
//例えば60 = 5*3*2*2 であれば[(5,1),(3,1),(2,2)]を返す
vector<pair<LL,LL>> factorial(LL x){
	vector<pair<LL,LL>> ret;
	for(LL i=2;i*i<=x;i++){
		if(x%i==0){
			LL counter = 0;
			while(1){
				if(x%i!=0) break;
				x /= i;
				counter++;
			}
			ret.push_back(make_pair(i,counter));
		}
	}
	if(x!=1) ret.push_back(make_pair(x,1));
	return ret;
}
 
LL N;
 
LL ans = 0;
 
void solve(){
	//N!の約数をfacts[素数] = その素数がいくつ含まれているか　で表現する
	map<LL,LL> facts;
	for(int i=1;i<=N;i++){
		vector<pair<LL,LL>> f = factorial(i);
		for(auto iter=f.begin();iter!=f.end();iter++){
			facts[iter->first] += iter->second;
		}
	}

	//75 = 1*75,5*15,3*25,3*5*5のいずれかで表せる。
	//75 = 1*75の時
	for(auto iter=facts.begin();iter!=facts.end();iter++){
		if(iter->second>=75 - 1) ans++;
	}
	//75 = 5*15の時
	for(auto iter=facts.begin();iter!=facts.end();iter++){
		if(iter->second>=5 - 1){
			for(auto iter_sub=facts.begin();iter_sub!=facts.end();iter_sub++){
				if(iter_sub==iter) continue;
				if(iter_sub->second>=15 - 1) ans++;
			}
		}
	}
	//75 = 3*25の時
	for(auto iter=facts.begin();iter!=facts.end();iter++){
		if(iter->second>=3 - 1){
			for(auto iter_sub=facts.begin();iter_sub!=facts.end();iter_sub++){
				if(iter_sub==iter) continue;
				if(iter_sub->second>=25 - 1) ans++;
			}
		}
	}
	//75 = 3*5*5の時
	for(auto iter=facts.begin();iter!=facts.end();iter++){
		if(iter->second>=3 - 1){
			for(auto iter_sub=facts.begin();iter_sub!=facts.end();iter_sub++){
				if(iter_sub==iter) continue;
				if(iter_sub->second>=5 - 1){
					for(auto iter_sub2=iter_sub;iter_sub2!=facts.end();iter_sub2++){
						if(iter_sub==iter_sub2 || iter_sub2==iter) continue;
						if(iter_sub2->second>=5 - 1) ans++;
					}
				}
			}
		}
	}
}
 
int main(){
    cin >> N;
 
    solve();
 
    cout << ans << endl;
    return 0;
}