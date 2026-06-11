# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i = 0; i< s.size(); i++){
		if(s[i] == '1') cout<<'9';
		else if(s[i] == '9') cout<<'1';
		else cout<< s[i];
	}
	cout<<'\n';
}
