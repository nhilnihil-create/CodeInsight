#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long int ll;

#define rep(i,n) for(int i = 0;i<n;++i)
#define repi(itr,vec) for(auto itr = vec.begin();itr!=vec.end();++itr)
#define MySort(conta) sort(conta.begin(),conta.end(), z::LessA)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

struct z{
	ll x;
	ll y;
	bool solved;
	static bool LessA(const z& rLeft, const z& rRight)
		{ return rLeft.x < rRight.x; } 
	static bool MoreY(const z& rLeft, const z& rRight)
		{ return rLeft.y > rRight.y; }
};

int main() {
	cin.tie(0);
        ios::sync_with_stdio(false);	
	ll n;
	cin >> n;
	vector<z> red(n);
	vector<z> blue(n);
	rep(i,n){
		cin >> red[i].x >> red[i].y;
	}
	rep(i,n){
		cin >> blue[i].x >> blue[i].y;
	}
	MySort(blue);
	sort(red.begin(),red.end(),z::MoreY);
	ll ans = 0;
	repi(itr,blue){
		repi(itr2,red){
			if(itr2->solved)continue;
			if(itr->x>itr2->x&&itr->y>itr2->y){
				itr2->solved = true;
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
