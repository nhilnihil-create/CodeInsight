#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
	string s;
	cin>>s;
	if(s.size()==2){
		cout<<s<<endl;
		return 0;
	}else{
		cout<<s.substr(2,1)+s.substr(1,1)+s.substr(0,1)<<endl;
	}
		return 0;
}

