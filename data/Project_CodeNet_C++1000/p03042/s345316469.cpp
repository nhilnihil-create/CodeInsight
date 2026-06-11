#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
bool fm,lm;
int main(){
	string s;cin>>s;
	int tmp=0;
	tmp+=s[1]-'0';tmp+=10*(s[0]-'0');
	if(tmp<=12&&tmp){
		fm=true;
	}
	tmp=s[3]-'0';tmp+=10*(s[2]-'0');
	if(tmp<=12&&tmp)lm=true;
	if(lm&&fm){
		cout<<"AMBIGUOUS";
	}else if(!lm&&!fm){
		cout<<"NA";
	}else if(lm&&!fm){
		cout<<"YYMM";
	}else{
		cout<<"MMYY";
	}
}