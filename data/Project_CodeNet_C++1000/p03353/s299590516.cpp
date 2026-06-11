#include <bits/stdc++.h>
using namespace std;

set<string> ms;
set<string>::iterator it;

int main(){
	string s,sub;
	int k;
	cin>>s>>k;
	for (int i=0;i<s.size();i++)
		for (int j=1;j<=5;j++){
			sub=s.substr(i,j);
			ms.insert(sub);
		}
			
	int cnt=0;
	for (it=ms.begin();it!=ms.end();it++){
		cnt++;
		if (cnt==k){
			cout<<*it<<endl;
			return 0;
		}
	}
	return 0;
}