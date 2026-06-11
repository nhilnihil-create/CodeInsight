#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    int cnt=0;
    while(t--){
    	int n;
    	cin>>n;
    	while(n%2==0){
    		n/=2;
    		++cnt;
    	}
    }
    cout<<cnt;
   	return 0;
}