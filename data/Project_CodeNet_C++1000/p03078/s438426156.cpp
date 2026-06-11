#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18

priority_queue<llint,vector<llint>,greater<llint>> que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

llint x,y,z,k;

void solve(){
	cin >> x >> y >> z >> k;
	llint a[x],b[y],c[z];
	for(int i=0;i<x;i++)cin >> a[i];
	for(int i=0;i<y;i++)cin >> b[i];
	for(int i=0;i<z;i++)cin >> c[i];
	sort(a,a+x);
	reverse(a,a+x);
	sort(b,b+y);
	reverse(b,b+y);
	sort(c,c+z);
	reverse(c,c+z);
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			for(int l=0;l<z;l++){
				if((i+1)*(j+1)*(l+1)<=k) q.push(a[i]+b[j]+c[l]);
				else break;
			}
		}
	}
	for(int i=0;i<k;i++){
		cout << q.top() << endl;
		q.pop();
	}

}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
