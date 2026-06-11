#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a;
	vector<int>v(4);
	for(int i=0;i<6;i++){
		cin>>a;
		v[a]++;
	}
	bool f=true;
	for(int i=0;i<=4;i++){
		if(v[i]>=3) f=false;
	}
	if(f){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
