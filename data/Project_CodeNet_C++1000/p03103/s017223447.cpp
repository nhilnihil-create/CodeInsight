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

struct shop{
	ll a;int b;
};

bool operator<(const shop& x,const shop& y){
	return x.a<y.a;
}

int main() {
	int n,m;
	cin>>n>>m;
	shop s[alength];
	fori(n){cin>>s[i].a>>s[i].b;}
	sort(s,s+n);
	ll money=0;
	fori(n){
		if(m<=s[i].b){
			money+=s[i].a*m;
			cout<<money;
			return 0;
		}else{
			money+=s[i].a*s[i].b;
			m-=s[i].b;
		}
	}
}