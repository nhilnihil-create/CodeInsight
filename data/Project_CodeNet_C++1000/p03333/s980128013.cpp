#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> > l, r, v;
	vector<bool> ischecked(n, false);
	for(int i = 0; i < n; i++){
		int tmpl, tmpr;
		cin >> tmpl >> tmpr;
		l.push_back(make_pair(-tmpl, i));
		r.push_back(make_pair(tmpr, i));
		v.push_back(make_pair(tmpl, tmpr));
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	long long int res1 = 0;
	int pos = 0;
	int il = 0, ir = 0;
	while(il < n || ir < n){
		while(il < n && ischecked[l[il].second]) il++;
		if(il < n){
			int nowi = l[il].second;
			ischecked[nowi] = true;
			int nowl = v[nowi].first;
			int nowr = v[nowi].second;
			if(pos > nowr){
				res1 += pos - nowr;
				pos = nowr;
			} else if(pos < nowl){
				res1 += nowl - pos;
				pos = nowl;
			}
		}
		// cout << pos << endl;
		while(ir < n && ischecked[r[ir].second]) ir++;
		if(ir < n){
			int nowi = r[ir].second;
			ischecked[nowi] = true;
			int nowl = v[nowi].first;
			int nowr = v[nowi].second;
			if(pos > nowr){
				res1 += pos - nowr;
				pos = nowr;
			} else if(pos < nowl){
				res1 += nowl - pos;
				pos = nowl;
			}
		}
		// cout << pos << endl;
	}
	res1 += abs(pos);
	// cout << "res1 : " << res1 <<  endl;
	long long int res2 = 0;
	pos = 0;
	il = 0;
	ir = 0;
	ischecked = vector<bool>(n, false);
	while(il < n || ir < n){
		while(ir < n && ischecked[r[ir].second]) ir++;
		if(ir < n){
			int nowi = r[ir].second;
			ischecked[nowi] = true;
			int nowl = v[nowi].first;
			int nowr = v[nowi].second;
			if(pos > nowr){
				res2 += pos - nowr;
				pos = nowr;
			} else if(pos < nowl){
				res2 += nowl - pos;
				pos = nowl;
			}
		}
		// cout << pos << endl;
		while(il < n && ischecked[l[il].second]) il++;
		if(il < n){
			int nowi = l[il].second;
			ischecked[nowi] = true;
			int nowl = v[nowi].first;
			int nowr = v[nowi].second;
			if(pos > nowr){
				res2 += pos - nowr;
				pos = nowr;
			} else if(pos < nowl){
				res2 += nowl - pos;
				pos = nowl;
			}
		}
		// cout << pos << endl;
	}
	res2 += abs(pos);
	// cout << "res2 : " << res2 << endl;
	cout << max(res1, res2) << endl;
}