#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n;
	cin>>n;
	vector<vector<long long>> shop(n,vector<long long>(10));
	vector<vector<long long>> point(n,vector<long long>(11));

	for(long long i=0;i<n;i++){
		for(long long j=0;j<10;j++){
			cin>>shop.at(i).at(j);
		}
	}

	for(long long i=0;i<n;i++){
		for(long long j=0;j<11;j++){
			cin>>point.at(i).at(j);
		}
	}

	long long ans=inf*-1;

	for(long long tmp=1;tmp<(1<<10);tmp++){
		bitset<10> bits=tmp;
		vector<long long> zyuhuku(n,0);
		long long pre=0;

		for(long long i=0;i<n;i++){
			for(long long j=0;j<10;j++){
				if(shop.at(i).at(j)==1 && bits.test(j)){
					zyuhuku.at(i)++;
				}
			}
		}

		for(long long i=0;i<n;i++){
			pre+=point.at(i).at(zyuhuku.at(i));
		}

		ans=max(ans,pre);
	}

	cout<<ans<<endl;

	return 0;
}
