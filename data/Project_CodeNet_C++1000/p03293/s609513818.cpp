#include<bits/stdc++.h>
using namespace std;
string xuan(string a){
	char c=a[a.size()-1];
	for(int i=a.size()-1;i>0;i--)
	a[i]=a[i-1];
	a[0]=c;
	return a;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		if(a==b){
			cout<<"Yes\n";
			return 0;
		}
		a=xuan(a);
	}
	cout<<"No\n";
    return 0;
}
