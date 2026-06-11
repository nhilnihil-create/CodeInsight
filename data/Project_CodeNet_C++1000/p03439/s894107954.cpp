#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,s,g,m;
string t,t1;
int main(void){
    cin>>n;
    g=n;
    cout<<s<<endl;
    cin>>t;
    while(t!="Vacant"){
        m=(s+g)/2;
        cout<<m<<endl;
        cin>>t1;
        if((t1==t)^(s%2==m%2))g=s;
        s=m;
        t=t1;
    }
}
