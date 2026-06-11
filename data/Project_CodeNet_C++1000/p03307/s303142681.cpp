#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll n;
    cin>>n;
    cout<<((n&1)?n*2:n);
  	return 0;
}