#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t[3];
int main(void){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        t[s[i]-'a']++;
    }
    int a=min({t[0],t[1],t[2]});
    t[0]-=a,t[1]-=a,t[2]-=a;
    if(t[0]<=1&&t[1]<=1&&t[2]<=1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
