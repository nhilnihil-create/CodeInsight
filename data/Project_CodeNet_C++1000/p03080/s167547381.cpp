#include<bits/stdc++.h>
#include<iostream>


using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R')++count;
    }
    int b=n-count;
    int ans=b-count;
    if(ans>=0)cout<<"No"<<endl;
    if(ans<0)cout<<"Yes"<<endl;
    return 0;
}

