#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)

typedef long long ll;
#define INF 1e18

int main(){
	ll x,y;
	cin>>x>>y;
	ll lcm=0;
	ll a=x,b=y,r=1;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	lcm=x/a*y;
	for(ll i=0;i<=lcm;i+=x){
		if(i%y!=0){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
