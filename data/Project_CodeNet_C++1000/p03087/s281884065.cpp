#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	vector<long long int> v;
	for(long long int i=0;i<s.size()-1;){
		if(s[i]=='A'&&s[i+1]=='C'){
			v.push_back(i);
			i+=2;
		}
		else{
			i++;
		}
	}
	sort(v.begin(),v.end());
	while(q--){
		long long int l,r;
		//long long int c=0;
		cin>>l>>r;
		l--;r--;
		long long int li=lower_bound(v.begin(),v.end(),l)-v.begin();
		long long int ri=lower_bound(v.begin(),v.end(),r)-v.begin();
		cout<<ri-li<<"\n";
	}
	return 0;
}