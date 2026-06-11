#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n;
	cin>>n;
	ll x[1000], y[1000];
	cin>>x[0]>>y[0];
	bool odd=0;
	if((x[0]+y[0])%2) odd=1;
	for(int i=1; i<n; i++){
		cin>>x[i]>>y[i];
		if((!odd && (x[i]+y[i])%2!=0) || (odd && (x[i]+y[i])%2==0)){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<40<<endl;
	ll d[40];
	if(odd){
		for(int i=39; i>=0; i--){
			cout<<(1ll<<i)<<" ";
			d[39-i]=(1ll<<i);
		}
		cout<<endl;
	}else{
		for(int i=38; i>=0; i--){
			cout<<(1ll<<i)<<" ";
			d[38-i]=(1ll<<i);
		}
		d[39]=1;
		cout<<1<<endl;
	}
	for(int i=0; i<n; i++){
		ll xn=0, yn=0;
		string ans;
		for(int j=0; j<40; j++){
			if(abs(xn-x[i])>abs(yn-y[i])){
				if(xn>x[i]){
					ans+='L';
					xn-=d[j];
				}else{
					ans+='R';
					xn+=d[j];
				}
			}else{
				if(yn>y[i]){
					ans+='D';
					yn-=d[j];
				}else{
					ans+='U';
					yn+=d[j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}