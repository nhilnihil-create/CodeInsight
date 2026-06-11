#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e8, cnt;
ll a[3];
int main(){
	string s;
	cin>>s;
	ll n=s.size();
	for(ll i=0; i<s.size(); i++){
		if(s[i]=='a') a[0]++;
		else if(s[i]=='b') a[1]++;
		else a[2]++;
	}
	sort(a,a+3);
	if(a[0]==0 && a[1]==0 && a[2]==1) cout<<"YES";
	else if(a[0]==0 && a[1]==1 && a[2]==1) cout<<"YES";
	else if(s.size()%3==0){
		if(a[0]==s.size()/3 && a[1]==s.size()/3 && a[2]==s.size()/3) cout<<"YES"<<endl;
		else cout<<"NO";
	}
	else {
		if(a[0]==n/3 && a[1]==(n/3)+1 && a[2]==(n/3)+1){
			cout<<"YES";
		}
		else if(a[0]==n/3 && a[1]==(n/3) && a[2]==(n/3)+1){
			cout<<"YES";
		}
		else cout<<"NO";
	}

}