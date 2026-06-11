#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main(){
    int A,B,C;
	cin >> A >> B >> C;
	if(A < B) swap(A,B);
	if(A < C) swap(A,C);
	int ans = (A-B)/2 + (A-C)/2;
	if((A-B)&1){
		if((A-C)&1) ++ans;
		else ans += 2;
	} else if((A-C)&1) ans += 2;
	cout << ans << endl;
	return 0;
}  