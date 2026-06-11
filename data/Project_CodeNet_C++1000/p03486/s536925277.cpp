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
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());sort(t.begin(),t.end(),greater<char>());
	if(s<t){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}