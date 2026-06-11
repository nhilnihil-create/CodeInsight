#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long n,m;
	cin>>n>>m;
	vector<long long> yakusu;

	for(long long i=1;i*i<=m;i++){
		if(m%i==0){
			yakusu.push_back(i);
			yakusu.push_back(m/i);
		}
	}

	sort(yakusu.begin(),yakusu.end());
	reverse(yakusu.begin(),yakusu.end());

	for(auto a:yakusu){
		if(m/a>=n){
			cout<<a<<endl;
			return 0;
		}
	}

	return 0;
}
