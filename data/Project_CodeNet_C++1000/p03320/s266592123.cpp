//arc099_d.cpp
//Sun Mar  1 10:11:46 2020
 
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;
 
ll calcsn(ll x){
	ll ans = 0;
	while(x>0){
		ans += x%10;
		x /= 10;
	}
	return ans;
}
 
int main(){
	int k;
	cin >> k;
 
	ll keta = 0;
	ll base = 1;
	ll num = 1;
	while (k){
		ll temp = num*base+base-1;
		ll sn = calcsn(temp);
		if (temp<=base*sn){
			cout << temp << endl;
			num++;
			k--;
		}else {
			keta++;
			base = pow(10,keta);
			num = 1;
			ll temp2 = num*base+base-1;
			while (temp2<=temp){
				num++;
				temp2 = num*base+base-1;
			}
		}
	}
 
}
//arc099_d.cpp
//Sun Mar  1 10:11:46 2020
