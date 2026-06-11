#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>

using namespace std;
typedef long long ll;


ll ans=1e18,mx,mn=1e8,sum,cnt;

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	ans = (a+b)+1;
	if(ans > c) cout<< b+c;
	else cout<< ans + b<<endl;
}
