#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    map<string,int> mp;
    int n;
    cin>>n;
    string s;
    rep(i,n){
        cin>>s;
        if(mp.count(s)==0) mp[s]=1;
        else mp[s]++;
    }
    int m;
    cin>>m;
    string t;
    rep(i,m){
        cin>>t;
        if(mp.count(t)==0) mp[t]=-1;
        else mp[t]--;
    }
    int maxi=0;
    for(auto it=mp.begin();it!=mp.end();it++) maxi=max(maxi,it->second);
    cout<<maxi;
}