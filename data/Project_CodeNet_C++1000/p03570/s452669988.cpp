#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())


inline int popCount(unsigned int x) {
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003F;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;

	int st=0;
	int last=-1;
	unordered_map<int,int> mp;
	mp.reserve(s.size());
	mp[0] = 0;

	for (char c : s){
		int minv=INF;
		st ^= 1 << (c-'a');

		auto it = mp.find(st);
		if (it != mp.end())minv = min(minv, it->second + 1);
		rep(i,26){
			it = mp.find(st ^ (1<<i));
			if (it != mp.end())
				minv = min(minv, it->second + 1);
		}

		
		if (minv != INF){
			it = mp.emplace(st, minv).first;
			it->second = min(it->second, minv);
		}
		last = minv;
	}

	cout<<last<<endl;


	return 0;
}