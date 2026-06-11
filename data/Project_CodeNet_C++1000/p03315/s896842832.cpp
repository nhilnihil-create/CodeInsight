#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>

using namespace std;
typedef long long ll;

ll ans, mx, mn, flag, sum, cnt;

int main(){
	string s;
	cin>>s;
	for(ll i=0; i<4; i++) {
		if(s[i]=='+') ans++;
		else ans--;
	}
	cout<<ans;
}
