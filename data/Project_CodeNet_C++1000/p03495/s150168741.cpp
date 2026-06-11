#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,k;
	cin>>n>>k;
	map<long long int,long long int> m;
	vector<long long int> v;
	set<long long int> s;
	while(n--){
		long long int x;
		cin>>x;
		s.insert(x);
		m[x]++;
	}
	set<long long int>::iterator it;
	for(it=s.begin();it!=s.end();it++){
		v.push_back(m[*it]);
	}
	sort(v.begin(),v.end());
	if(v.size()<=k){
		cout<<"0";
	}
	else{
		long long int i=0;
		long long int ans=0;
		long long int delta=v.size()-k;
		while(delta--){
			ans+=v[i];
			i++;
		}
		cout<<ans;
	}
	return 0;
}