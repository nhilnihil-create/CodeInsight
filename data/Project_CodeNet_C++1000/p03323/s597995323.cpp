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
    (a>8 || b>8)?cout<<":(":cout<<"Yay!";
	return 0;
}