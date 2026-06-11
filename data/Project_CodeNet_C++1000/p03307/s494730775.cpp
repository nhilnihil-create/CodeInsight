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
    cout<<((n%2==0)?n:n*2);
  	return 0;
}