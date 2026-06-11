#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	string s;
	cin>>s;
	map<char,bool> tes;
	tes['A']=true;
	tes['C']=true;
	tes['G']=true;
	tes['T']=true;

	long long ans=0;
	long long cnt=0;
	for(auto a:s){
		if(tes.count(a)) cnt++;
		else cnt=0;
		ans=max(ans,cnt);
	}

	cout<<ans<<endl;

	return 0;
}
