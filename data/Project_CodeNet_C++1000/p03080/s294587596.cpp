#include<bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

int main(){
	int n,cnt=0;
	string s;
	cin>>n>>s;

	for (int i = 0; i < s.size(); ++i){
		if(s[i]=='R')
			cnt++;
	}

	if(cnt>n-cnt){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
