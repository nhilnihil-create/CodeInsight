#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int number(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    int n;cin>>n;
    int ans=0;
    if(n==10||n==100||n==1000||n==10000||n==100000)ans=10;
    else ans=number(n);

    cout<<ans<<endl;
}