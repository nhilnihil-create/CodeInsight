#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;


int main(){
	ll k,a,b;
	cin>>k>>a>>b;
	ll bis=1;
	if(b<=a+2){
		cout<<k+1;
		return 0;
	}
	while(k>0){
		if(bis>=a){
			if(k>=2){
				bis-=a;
				bis+=b;
				k-=2;
			}
			else {
				bis+=k;
				k=0;
			}
		}
		else{
			ll result=a-bis;
			if(k>=result){
				k-=result;
				bis+=result;
			}
			else{
				bis+=k;
				k=0;
			}
		}
	}
	cout<<bis<<endl;
}
