#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    char c;
    int ans=0;
    while(cin>>c) (c=='+')?++ans:--ans;
   	cout<<ans;
   return 0;
}