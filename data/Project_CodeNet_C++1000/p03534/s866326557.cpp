#include <bits/stdc++.h>
using namespace std;
string s;
int a,b,c;

int main(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='a'){
			a++;
		}else if(s[i]=='b'){
			b++;
		}else{
			c++;
		}
	}
	int t;
	t=min(a,min(b,c));
	a-=t;
	b-=t;
	c-=t;
	if(a<2&&b<2&&c<2){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}