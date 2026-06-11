#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <bitset>
using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

bitset<4000001> b;
int main(){
	int n;
	cin >> n;
	b.set(0);
	rep(i,n){
		int a;
		cin >> a;
		b |= (b<<a);
		b.set(a);
	}
	int m = b.count();
	//cerr << m << endl;
	int k = m/2+1;
	//cerr << k << endl;
	int c = 0;
	for(int i=0;i<=4000000;i++){
		if(b[i])c++;
		if(c==k){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}