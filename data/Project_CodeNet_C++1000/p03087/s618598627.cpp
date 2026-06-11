#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1000000000000000001;
int main(){
    int n,q;cin >> n >> q;
    string s;cin>>s;
    int sum[n];
    int l[n],r[n];
    sum[0]=0;
    for(int i=1;i<n;i++){
    if(s[i-1]=='A'&&s[i]=='C')sum[i]=sum[i-1]+1;
    else sum[i]=sum[i-1];
    }
    rep(i,q){
        cin>>l[i]>>r[i];
    }
    rep(i,q){
        int ans=0;
        if(l[i]>=2){
        ans=sum[r[i]-1]-sum[l[i]-1];
        cout << ans << endl;
        }
        if(l[i]==1){
        ans=sum[r[i]-1];
        cout << ans << endl;
        }
    }
 return 0;
}