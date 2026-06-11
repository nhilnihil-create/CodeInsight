#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>

#include <map>
 
using namespace std;
typedef long long ll; 


ll ans,mx,sum,mn=1e10,flag;

int main(){
	ll n,a,b,ans;
	cin>>n>>a>>b;
	ans = b-a;
	if(ans%2==0) cout<<"Alice";
	else cout<<"Borys";
}

