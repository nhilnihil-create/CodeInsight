#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int n;
	cin>>n;
	map<string,bool> m;
	string r;
	cin>>r;
	m[r]=true;
	fori(n-1){
		string s;
		cin>>s;
		if(r.back()!=s.front()){
			cout<<"No";
			return 0;
		}
		auto itr=m.find(s);
		if(itr!=m.end()){
			cout<<"No";
			return 0;
		}
		m[s]=true;
		r=s;
	}
	cout<<"Yes";
}