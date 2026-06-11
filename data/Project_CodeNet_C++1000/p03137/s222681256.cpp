#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1<<29;
int main(){
    int n,m;cin >> n >> m;
    int x[m];
    rep(i,m)cin>>x[i];
    sort(x,x+m);
    vector<int> d(m-1);
    if(n<m){
    rep(i,m-1)d[i]=x[i+1]-x[i];
    sort(all(d),greater<int>());
    int ans=0;
    for(int i=n-1;i<m-1;i++){
        ans+=d[i];
    }
    cout << ans << endl;
    }
    else cout << 0 << endl;
}