#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H,W,n,x,y;
	string s,t;
	cin>>H>>W>>n>>x>>y>>s>>t;
	for(int i=0;i<4;i++){
		char fi = "LRUD"[i];
		char se = "RLDU"[i];
		int z;
		if(i==0)	z=y;
		else if(i==1)	z=W-y+1;
		else if(i==2)	z=x;
		else z=H-x+1;
		int b;
		if(i<2)	b=W;
		else	b=H;
		for(int j=0;j<s.size();j++){
			if(s[j]==fi)	z--;
			if(z==0){
				cout<<"NO"<<endl;
				return 0;
			}
			if(t[j]==se&&z!=b)	z++;
		}
	}
	cout<<"YES"<<endl;
}

