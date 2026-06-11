#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s="#",w[100];
	cin>>n;
	bool ok=true;
	for(int i=0;i<n;i++){
		cin>>w[i];
		if(i){
			bool have=false;
			for(int j=0;j<i;j++) if(w[j]==w[i]) have=true;
			if(have||w[i-1][w[i-1].size()-1]!=w[i][0]) ok=false;
		}
	}
	if(ok) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
