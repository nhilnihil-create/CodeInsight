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
    int mx=0,mi=1000000000;
    while(t--){
    	int a;
    	cin>>a;
    	if(a>mx) mx=a;
    	if(a<mi) mi=a;
    }
   	cout<<mx-mi;
   return 0;
}