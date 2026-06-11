#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b;
    string s,t;
    cin>>a>>b;
    if((a+b)%2==0)
        cout<<(a+b)/2<<"\n";
    else cout<<(a+b)/2 + 1<<"\n";
    return(0);
}