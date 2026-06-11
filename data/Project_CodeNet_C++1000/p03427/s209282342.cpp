#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;

int main(){
	string n;
	cin>>n;
	int a=n.size();
	if(a==1){
		cout<<n[0]-'0'<<endl;
		return 0;
	}
	bool ok=false;
	for(int i=1;i<a;i++)if(n[i]!='9')ok=true;
	if(ok){
		int ans=(a-1)*9;
		ans+=(n[0]-'0'-1);
		cout<<ans<<endl;
	}else{
		cout<<9*(a-1)+(n[0]-'0')<<endl;
	}
	return 0;
}
