#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
	ll n,m,c,ans=0,sum;
	cin >> n >> m >> c;
	vector<ll> a(m),b(m);
	REP(i,m) cin >> b[i];
	REP(i,n){
		sum=0;
		REP(j,m) cin >> a[j];
		REP(j,m) sum += a[j]*b[j];
		if(sum+c > 0) ans++;
	}
	cout << ans << endl;
	
	return 0;
}