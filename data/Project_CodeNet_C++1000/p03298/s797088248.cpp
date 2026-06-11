#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string s;
int n;
vector<pair<string,string> >va,vb;
ll sol;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>s;
	for(int i=0;i<(1<<n);i++){
		string p,q;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				p+=s[j];
			}
		}
		for(int j=n-1;j>=0;j--){
			if(i&(1<<j)) continue;
			q+=s[j];
		}
		va.push_back(make_pair(p,q));
	}
	for(int i=0;i<(1<<n);i++){
		string p,q;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				p+=s[n+j];
			}
		}
		for(int j=n-1;j>=0;j--){
			if(i&(1<<j)) continue;
			q+=s[n+j];
		}
		vb.push_back(make_pair(q,p));
	}
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	for(int i=0;i<va.size();i++){
		int a=lower_bound(vb.begin(),vb.end(),va[i])-vb.begin();
		int b=upper_bound(vb.begin(),vb.end(),va[i])-vb.begin();
		if(a<vb.size()&&vb[a]==va[i]){
			sol+=b-a;
		}
	}
	cout<<sol<<"\n";
	return 0;
}