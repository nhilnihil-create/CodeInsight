#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<cmath>
#include<cstdio>
#include<set>
#include<map>
#include<iomanip>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >=0; i--)
#define lint long long
#define all(x) (x).begin(), (x).end()


int main(){
    int m,k; cin>>m>>k;
    if(m==0){
        if(k==0){ cout<<"0 0"<<endl; return 0;}
        else {cout<<"-1"<<endl; return 0;}
    }
    if(m==1){
        if(k==0){cout<<"0 1 1 0"<<endl; return 0;}
        else {cout<<"-1"<<endl; return 0;}
    }
    if(k >= pow(2, m)) {cout<<"-1"<<endl; return 0;}
    string ans = "";
    int n = pow(2, m);
    rep(i,n){
        if(i!=k) ans += to_string(i) + " ";
    }
    ans += to_string(k) + " ";
    repr(i,n){
        if(i!=k) ans += to_string(i) + " ";
    }
    ans += to_string(k);
    cout<<ans<<endl;
}