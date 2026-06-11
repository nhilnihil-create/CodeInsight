#include <bits/stdc++.h>
using namespace std;

int main() {
	long long d,g;
	cin >> d >> g;
	long long p[d],c[d];
	for(long long i=0;i<d;i++){
		cin >> p[i] >> c[i];
	}
	long long ans=10000;
	for(int bit=0;bit<(1<<d);bit++){
		vector<int> a(d,0);
		long long com=0;
		long long count=0;
		for(int i=0;i<d;i++){
			if(bit&(1<<i)){
				a[i]=1;
				count+=p[i];
				com+=(i+1)*100*p[i]+c[i];
			}
		}
		for(int i=d-1;i>=0;i--){
			if(a[i]==0){
				if(com>=g) break;
				else if(com<g && (com+(i+1)*100*(p[i]-1))<g){
					count+=10000;
					break;
				}
				else{
					for(int j=0;j<p[i];j++){
						if(com+(i+1)*100*j>=g){
							count+=j;
							break;
						}
					}
					break;
				}
			}
		}
		ans=min(ans,count);
	}
	cout << ans << endl;
}
