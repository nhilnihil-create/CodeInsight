#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main() {
  long long n, m;
  cin >> n >> m;
  map<int, int> mp;
  mp[1] = 2;
  mp[2] = 5;
  mp[3] = 5;
  mp[4] = 4;
  mp[5] = 5;
  mp[6] = 6;
  mp[7] = 3;
  mp[8] = 7;
  mp[9] = 6;
  vector<pair<int, int> > a(m);
  for(int i = 0; i < m; ++i){
    cin >> a[i].second;
    a[i].first = mp[a[i].second];
  }
  sort(a.begin(), a.end());
	vector<pair<int, bool> > d(n + 1, make_pair(0, false));
	vector<pair<int, int> > v(n + 1);
	d[0].second = true;
	d[0].first = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < m && a[j].first <= i; ++j)
		    if((d[i].first < d[i - a[j].first].first + 1 || (d[i].first == d[i - a[j].first].first + 1 && v[i].second <= a[j].second)) && d[i - a[j].first].second){
			    d[i].first = d[i - a[j].first].first + 1;
				  v[i].first = i - a[j].first;
          v[i].second = a[j].second;
				  d[i].second = true;
			}

 	}
	vector<int> path;
	long long p = n;
	for(int i = n; i != 0; i = v[i].first){
		path.push_back(v[i].second);
		p = v[i].first;
  }
  sort(path.begin(), path.end());
	for(int i = path.size() - 1; i >= 0; --i) cout << path[i];
}