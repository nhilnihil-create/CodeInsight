#include<bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<2*n/gcd(2,n);
  	return 0;
}