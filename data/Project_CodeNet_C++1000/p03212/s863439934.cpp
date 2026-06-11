#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include <cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<ctime>
#define rep(i,n) for (int i=0;i<n;i++)
//#include <bits/stdc++.h>
using namespace std;

long int N;

long int f(string s){
    long int l=stol(s),ans=0;
    int a=0,b=0,c=0;
    if (l>N) return 0;
    for (int i=0;i<s.size();i++){
        if (s[i]=='3') a=1;
        else if(s[i]=='5') b=1;
        else if (s[i]=='7') c=1; 
    }    
    if (a*b*c) ans=1;
    ans+=f(s+"3")+f(s+"5")+f(s+"7");
    return ans;
}


int main(){
    cin>>N;
    cout<<f("0")<<endl;

    return 0;
}