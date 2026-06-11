#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

long long solve(vector<long long> num,long long mid){
	long long ret=0;

	for(int i=0;i<(int)num.size();i++){
		ret+=abs(num.at(i)-mid);
	}

	return ret;
}

int main(){
	int n;
	cin>>n;
	vector<long long> num(n);

	for(int i=0;i<n;i++){
		cin>>num.at(i);
		num.at(i)-=i+1;
	}

	sort(num.begin(),num.end());

	cout<<min(solve(num,num.at(n/2)),solve(num,num.at(max(n/2-1,0))))<<endl;

	return 0;
}
