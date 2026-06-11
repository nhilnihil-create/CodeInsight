#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int h, w, n;
	cin>>h>>w>>n;
	vector<int> v[200001];
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int x=2; x<=h; x++) sort(v[x].begin(), v[x].end());
	int sy=1;
	for(int x=2; x<=h; x++){
		for(auto y:v[x]){
			if(y<=x-2+sy){
				cout<<x-1<<endl;
				return 0;
			}
			if(x-1==y-sy) sy--;
		}
	}
	cout<<h<<endl;
	return 0;
}