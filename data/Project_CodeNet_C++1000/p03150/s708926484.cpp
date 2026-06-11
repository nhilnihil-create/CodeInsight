#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	int n = s.size();
	string t = "keyence";
	if(s == t){
		cout<<"YES";
		return 0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			string hano = "";
			for(int k=0;k<i;k++){
				hano += s[k];
			}
			for(int k=j+1;k<n;k++){
				hano += s[k];
			}
			if(hano == t){
				cout<<"YES";
				return 0;
			}
		}
	}
	
	cout<<"NO";
	
	return 0;
}
