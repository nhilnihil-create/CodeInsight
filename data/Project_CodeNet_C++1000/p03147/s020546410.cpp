#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1<<27;
int main(){
    int n;cin>>n;
    int h[n];
    rep(i,n)cin>>h[i];
    int ans=0;
    ans+=h[0];
    for(int i=1;i<n;i++){
        if(h[i-1]<h[i]){
         ans+=h[i]-h[i-1];
        }
    }
cout << ans << endl;
}