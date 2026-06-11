#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	map<long long int,long long int> m;
	set<long long int> s;
	while(n--){
		long long int x;
		cin>>x;
		s.insert(x);
		m[x]++;
	} 
	set<long long int>::iterator it;
	long long int ans=0;
	for(it=s.begin();it!=s.end();it++){
		if(m[*it]<*it){
			ans+=m[*it];
		}
		else if(m[*it]>*it){
			ans+=m[*it]-*it;
		}
	}
	cout<<ans;
	return 0;
}