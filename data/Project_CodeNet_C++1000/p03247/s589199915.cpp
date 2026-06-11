#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int x[2000], y[2000], xy[2]={0,0}, n;
vector<int> v;
char g;
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d%d",&x[i],&y[i]);
		xy[(x[i]+y[i])%2]=1;
	}
	if (xy[0] && xy[1]) {
		printf("-1\n");
		return 0;
	}
	if (xy[0]) v.pb(1);
	for(int i=1<<30; i>0; i>>=1) {
		v.pb(i);
	}
	printf("%d\n",v.size());
	for(int i=0; i<v.size(); i++) {
		printf(i==v.size()-1?"%d\n":"%d ",v[i]);
	} 
	for(int i=0; i<n; i++) {
		int xx=0, yy=0;
		for(int j=0; j<v.size(); j++){
			if (abs(x[i]) > abs(y[i])) {
				if (x[i] > 0) {x[i]-=v[j]; g = 'R';}
				else {x[i]+=v[j]; g = 'L';}
			} else {
				if (y[i] > 0) {y[i]-=v[j]; g = 'U';}
				else {y[i]+=v[j]; g = 'D';}
			}
			printf("%c",g);
		}
		printf("\n");
	}
	return 0;
}