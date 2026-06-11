#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(i,n,x) for(int i=0;i<n;i+=x)
#define pb push_back
int main(){
	int n,h,w;
	cin>>n>>h>>w;
	int ans=(n-(h-1))*(n-(w-1));
	cout<<ans;
}