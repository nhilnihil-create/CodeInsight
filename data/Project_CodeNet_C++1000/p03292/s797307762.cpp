#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({a,b,c})-min({a,b,c});
  	return 0;
}