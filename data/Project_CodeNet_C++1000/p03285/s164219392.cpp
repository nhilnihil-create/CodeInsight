#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll ans, mx, sum,temp, mn = 1e14, flag,cnt;

int main(){
	ll n;
	cin>>n;
	for(ll i=0; i<=100; i++){
		for(ll j=0; j<=100; j++){
			ll ans=(i*4)+(j*7);
			if(ans==n){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
}
