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
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    string ans="UNRESTORABLE";
    rep(i,n-m+1){
        string u=s;
        bool flag=true;
        rep(j,m){
            if(u[i+j]=='?') u[i+j]=t[j];
            if(u[i+j]!=t[j]) flag=false;
        }
        if(!flag) continue;
        rep(j,n) if(u[j]=='?') u[j]='a';
        ans=u;
    }
    cout<<ans;
}