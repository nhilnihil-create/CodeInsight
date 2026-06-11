#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> era(int N){
	vector<int> is_prime(N+1,1);
	is_prime[0]=0;
	is_prime[1]=0;
	for(int p=2;p*p<=N;p++){
		if(!is_prime[p])continue;
		for(int i=p*2;i<=N;i+=p)is_prime[i]=0;
	}
	return is_prime;
}

signed main(){
	int N; cin>>N;
	vector<int> prime=era(N);
	vector<int> pri;
	for(int i=0;i<N+1;i++){
		if(prime[i]==1)pri.push_back(i);
	}
	map<int,int> fact;
	for(int i=2;i<=N;i++){
		int j=0;
		while(j<pri.size()){
			int tmp=i;
			while(tmp%pri[j]==0){
				fact[pri[j]]++;
				tmp/=pri[j];
			}
			j++;
		}
	}
	vector<int> f(100,0);
	for(auto p : fact){
		f[p.second]++;
	}
	for(int i=99;i>0;i--){
		f[i-1]+=f[i];
	}
	int ans=0;
	ans+=f[74];
	ans+=f[14]*(f[4]-1);
	ans+=f[24]*(f[2]-1);
	ans+=f[4]*(f[4]-1)/2*(f[2]-2);
	cout<<ans<<endl;

}