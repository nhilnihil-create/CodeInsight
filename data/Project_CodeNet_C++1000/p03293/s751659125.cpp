#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;

int a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s,t;
	cin>>s>>t;
	
	int n = (int)s.size();
	for(int i=0;i<n;i++){
		if(s == t){
			cout<<"Yes";
			return 0;
		}
		t = t[n-1]+t;
		t.pop_back();
	}
	cout<<"No";
	
	return 0;
}
