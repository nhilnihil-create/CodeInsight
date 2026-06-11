#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define x first
#define y second
#define ll long long
#define dl double
#define pii pair<int,int>
#define pb push_back
#define all() begin(),end()
#define nl '\n'
#define adm(a,b,m) ((a+b)%m)
#define gum(a,b,m) ((a*1LL*b)%m)
#define lo(i,j,n) for(int i=j;i<n;i++)


int main(){
	int a,b;
	cin>>a>>b;
	if(a<b)swap(a,b);
	if(a-b<=1)
	cout<<"Yay!"<<nl;
	else
	cout<<":("<<nl;
}
