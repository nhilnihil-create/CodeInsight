#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

ll ans,mx,sum,mn=1e8,cnt;

int main(){
	ll n;
	cin>>n;
	ll m=0;
	while(n>0){    
		m=n%10;    
		sum=sum+m;    
		n=n/10;
		ans++;    
	} 
//	cout<<sum<<endl;  
	cout<<max(sum,(9*(ans-1))+(m-1))<<endl;
	
}
