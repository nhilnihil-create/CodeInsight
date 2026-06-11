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

int n;
int a[200001];

bool validate(int mid)
{
	map<int, int> m;
	for(int i = 1; i < n; i++){
		if(a[i - 1] < a[i]){
			continue;
		}
		if(mid == 1) return false;
		auto itr = m.find(a[i]);
		if(itr == m.end()){
			m[a[i]] = 2;
			itr = m.find(a[i]);
			m.erase(++itr, m.end());
		} else {
			// a[i]以下で、かつm[v]がundefindedまたはm[v] < midとなるようなvを探す
			for(int j = a[i]; j >= 1; j--){
				itr = m.find(j);
				if(itr == m.end()){
					// m[j]がundefinedなのでこれをインクリメント
					m[j] = 2;
					itr = m.find(j);
					m.erase(++itr, m.end());
					break;
				} else if(m[j] < mid){
					// m[j] < midなるjなのでこれをインクリメント
					(*itr).second++;
					m.erase(++itr, m.end());
					break;
				} else if(j == 1){
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int l = 0, r = n;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if(validate(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
}