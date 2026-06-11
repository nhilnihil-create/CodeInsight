#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main(){
	int n,q;
	string s;
	cin>>n>>s>>q;
	while (q--) {
		int k;cin>>k;
		ll d=0,m=0,dm=0,dmc=0,i;
		for(i=0;i<k;i++){
			switch (s[i]) {
				case 'D':
					d++;
					break;
					
				case 'M':
					dm+=d;
					m++;
					break;
					
				case 'C':
					dmc+=dm;
			}
		}
		for(;i<n;i++){
			switch (s[i-k]) {
				case 'D':
					d--;
					dm-=m;
					break;
					
				case 'M':
					m--;
			}
			switch (s[i]) {
				case 'D':
					d++;
					break;
					
				case 'M':
					dm+=d;
					m++;
					break;
					
				case 'C':
					dmc+=dm;
			}
		}
		printf("%lld\n",dmc);
	}
}
