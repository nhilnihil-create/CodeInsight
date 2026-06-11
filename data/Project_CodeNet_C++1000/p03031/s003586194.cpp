#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n,m;
	cin>>n>>m;
	vector<vector<long long>> light(m);
	vector<long long> p(m);

	for(long long i=0;i<m;i++){
		long long k;
		cin>>k;
		for(long long j=0;j<k;j++){
			long long hoge;
			cin>>hoge;
			light.at(i).push_back(hoge);
		}
	}

	for(long long i=0;i<m;i++){
		cin>>p.at(i);
	}

	long long ans=0;

	for(long long tmp=0;tmp<(1<<n);tmp++){
		bitset<10> bits=tmp;
		long long cnt=0;

		for(long long i=0;i<m;i++){
			long long pre=0;
			for(auto a:light.at(i)){
				if(bits.test(a-1)) pre++;
			}

			if(pre%2==p.at(i)) cnt++;
		}

		if(cnt==m) ans++;
	}

	cout<<ans<<endl;

	return 0;
}
