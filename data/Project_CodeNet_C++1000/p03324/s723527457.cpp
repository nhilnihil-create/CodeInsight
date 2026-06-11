#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b;
    cin>>a>>b;
   	(b==100)?cout<<101:cout<<b;
   	if(a==1) cout<<"00";
   	else if(a==2) cout<<"0000";
   	return 0;
}