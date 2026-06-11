#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=1e5+10;
void io(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	io();
	int n,k;
	cin>>n>>k;
	if(n<k)cout<<"1"<<endl;
	else {
		cout<<n-k+1<<endl;
	}
	return 0;
}