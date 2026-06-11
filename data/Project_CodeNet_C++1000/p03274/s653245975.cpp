#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<long long>minus(1,0);
	vector<long long>plus(1,0);
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		if(a>=0) plus.push_back(a);
		else minus.push_back(-1*a);
	}
	sort(minus.begin(),minus.end());
	sort(plus.begin(),plus.end());
	long long mindist = numeric_limits<long long>::max();
	for(int i=0; i<plus.size(); i++){
		if(i>k) break;
		int pick = k-i;
		if(pick>=minus.size() || pick<0) continue;
		
		long long dist = plus[i]*2+minus[pick];
		mindist = min(mindist,dist); 
		dist = plus[i]+2*minus[pick];
		mindist = min(mindist,dist);
	}
	cout<<mindist;
}