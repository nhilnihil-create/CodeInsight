#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()

int main(){
	int n=3;
	vector<string> v;
	for (int bit=0; bit<(1<<n); bit++){
		string s;
		for (int i=0; i<n; i++){
			if (bit &(1<<i)) s+="+";
			else s+="-";
		}
		v.push_back(s);
	}
	
	string x; cin>>x;
	for(int k=0; k<(int)v.size(); k++){
		int ans=x[0]-'0';
		string y=to_string(ans);
		string t=v[k];
		for(int i=1; i<4; i++){
			if(t[i-1]=='+'){ans+=x[i]-'0'; y+=t[i-1]+to_string(x[i]-'0');}
			else{ans-=x[i]-'0'; y+=t[i-1]+to_string(x[i]-'0');}
		}
		if(ans==7){cout<<y<<"=7"<<endl; return 0;}
	}
}