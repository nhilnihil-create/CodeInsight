#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N,P;cin>>N>>P;
	map<long long,int> m;
	for(long long i=2;i*i<=P;i++){
		while(P%i == 0){
			m[i] += 1;
			P /= i;
		}
	}
	
	if(P > 1) m[P] += 1;
	long long ans = 1;
	for(auto x: m) {
		int times = x.second / N;
		for(int i=0;i<times;i++) ans *= x.first;
	}
	cout<<ans<<endl;
	
}