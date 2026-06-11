#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	long long x,ans=0;
	cin>>x;
	for(int i=0;i<x;i++){
		int a=i+1;
		for(int j=0;j<20;j++){
			a*=i+1;
			if(x>=a && a>ans){
				ans=a;
			}
			if(x<a){
				break;
			}
		}
	}
	cout<<ans<<endl;
    return(0);
}