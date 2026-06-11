#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	double sum=0;
	while(t--){
		double n;
		string s;
		cin>>n>>s;
		if(s=="JPY") sum+=n;
		else sum+=n*380000.0;
	}
	cout<<sum;
	return 0;
}
