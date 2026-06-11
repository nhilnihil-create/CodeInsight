#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

vector<int> ls[2];
int main() {
	string s;
	cin >> s;
	int x[2];
	cin >> x[0] >> x[1];
	int c=0;
	int f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='F'){
			c++;
		}
		else{
			if(i==c){
				x[0]-=c;
			}
			else if(c){
				ls[f].push_back(c);
			}
			c=0;
			f^=1;
		}
	}
	if(c){
		if(c==s.size()){
			x[0]-=c;
		}
		else{
			ls[f].push_back(c);
		}
	}
	//cerr << ls[0].size() << endl;
	for(int k=0;k<2;k++){
		vector<int> cur,nex;
		cur.push_back(0);
		for(int v:ls[k]){
			nex.clear();
			for(auto p:cur){
				nex.push_back(p-v);
				nex.push_back(p+v);
			}
			sort(nex.begin(),nex.end());
			nex.resize(unique(nex.begin(),nex.end())-nex.begin());
			swap(cur,nex);
		}
		auto it=lower_bound(cur.begin(),cur.end(),x[k]);
		/*
		for(int p:cur){
			cerr << p << " ";
		}
		cerr << endl;
		*/
		if(it==cur.end()||*it!=x[k]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}

