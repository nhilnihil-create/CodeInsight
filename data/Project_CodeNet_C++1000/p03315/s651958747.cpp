#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    char c;
    int plus=0,minus=0;
    while(cin>>c) (c=='+')?++plus:++minus;
   	cout<<plus-minus;
   return 0;
}