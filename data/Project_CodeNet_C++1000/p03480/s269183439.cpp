#include<bits/stdc++.h>
using namespace std;
string s;
int minn=1e9;
int main(){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n-1;i++){
		if(s[i]!=s[i+1]){
			minn=min(minn,max(n-i-1,i+1));
		}
	}
	if(minn==1e9){
		cout<<n;
	}
	else
	{
		cout<<minn;
	}
} 