#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b=0,n;
    string s,t;
    cin>>n;
    a=n;
    while(a>0){
        b+=a%10;
        a/=10;
    }
    if(n%b==0) cout<<"Yes\n";
    else cout<<"No\n";
    return(0);
}