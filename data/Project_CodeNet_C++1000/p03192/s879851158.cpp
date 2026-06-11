#include<iostream>
using namespace std;
string a;
int ans;
int main(){
	cin>>a;
	if(a[0]=='2') ans++;
	if(a[1]=='2') ans++;
	if(a[2]=='2') ans++;
	if(a[3]=='2') ans++;
	cout<<ans;
	return 0;
}