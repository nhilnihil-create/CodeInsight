#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 4000000000000000001


int main(){

	int N,K;
	cin>>N>>K;
	
	vector<long long> x(N),y(N);
	
	vector<pair<long long,long long>> P(N);
	
	for(int i=0;i<N;i++){
		cin>>P[i].first>>P[i].second;
		x[i] = P[i].first;
		y[i] = P[i].second;
	}
	
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	long long ans = Inf;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for(int k=0;k<N;k++){
				for(int l=k+1;l<N;l++){
					
					int cnt = 0;
					for(int ind=0;ind<N;ind++){
						if(x[i]<=P[ind].first&&x[j]>=P[ind].first&&y[k]<=P[ind].second&&y[l]>=P[ind].second){
							cnt++;
						}
					}
					if(cnt>=K){
						ans = min(ans,(x[j]-x[i])*(y[l]-y[k]));
					}
					
					
				}
			}
		}
	}
	
	cout<<ans<<endl;
	
    return 0;
}

