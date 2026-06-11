#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	map<long long,int>mm;
	map<long long,int>::iterator it;
	long long sum = 0;
	long long ret = 0;
	mm.insert(make_pair(0,1));
	while(n--){
		long long a;
		cin>>a;
		sum+=a;
		long long mod = sum%m;
		it = mm.find(mod);
		if(it==mm.end()) mm.insert(make_pair(mod,1));
		else{
			ret+=it->second;
			it->second+=1;
		}
	}
	cout<<ret;
}